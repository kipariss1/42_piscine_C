#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <utmp.h>
#include "libft.h"

#ifndef SHUTDOWN_TIME
# define SHUTDOWN_TIME 254
#endif

/* month and days declaration */
char *days[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int initial_year = 1970;

/* Double linked list of struct utmp's */
struct utmplist {
	struct utmp ut;
	struct utmplist *next;
	struct utmplist *prev;
};

/* last time formats */
struct last_timefmt {
    const char *name;
    int in_len;
    int in_fmt;
    int out_len;
    int out_fmt;
};

/* types of listing */
enum {
    R_CRASH = 1,
    R_DOWN,
    R_NORMAL,
    R_NOW,
    R_REBOOT,
    R_REBOOT_CRASH,
    R_PHANTOM,
    R_TIMECHANGE,
};

/* times of formats */
enum {
	LAST_TIMEFTM_NONE = 0,
	LAST_TIMEFTM_SHORT,
	LAST_TIMEFTM_CTIME,
	LAST_TIMEFTM_ISO8601,

	LAST_TIMEFTM_HHMM,	/* non-public */
};

static struct last_timefmt short_fmt = {
    .name       = "short",
    .in_len     = 15,
    .out_len    = 7,
    .in_fmt     = LAST_TIMEFTM_CTIME,
    .out_fmt    = LAST_TIMEFTM_HHMM
};


// Global vars
static time_t lastdate;
static time_t currentdate;

int time_formatter(int fmt, char *dst, time_t *when){

    switch (fmt)
    {
    case LAST_TIMEFTM_HHMM:
    {
        // convert "when" time to "- 20:27" format
        // *when = *when + 3600;       // adding one hour, because my time is GMT+1
        int mins = (*when / 60) % 60;
        char mins_str[3] = {'\0'};
        ft_int_to_str(mins_str, mins, 2);

        int hours = (*when / 3600) % 24;
        char hours_str[3] = {'\0'};
        ft_int_to_str(hours_str, hours, 2);       

        char time_str[5] = {'\0'};
        ft_strcpy(time_str, hours_str);
        ft_strcpy(time_str+2, ":");
        ft_strcpy(time_str+3, mins_str);

        ft_strcpy(dst, time_str);

        break;
    }

    case LAST_TIMEFTM_CTIME:
    {
        // convert "when" time to "Sat Mar 23 20:27" fmt
        // *when = *when + 3600;       // adding one hour, because my time is GMT+1
        int days_total = *when / 86400;
        int curr_day_of_the_week = (days_total+3)%7;

        int curr_day = 0;
        int curr_month = 0;
        int curr_year = initial_year;
        int days_left_in_month = days_in_month[curr_month];
        while  (days_total){
            if (!days_left_in_month){
                if (curr_month == 11){
                    curr_month = 0;
                    curr_year++;

                    // if is leap year
                    if ((!(curr_year%4) && (curr_year%100)) || (!(curr_year%400))){
                        days_in_month[1] = 29;
                    }
                    else {
                        days_in_month[1] = 28;
                    }
                }
                else {
                    curr_month++;
                }
                
                days_left_in_month = days_in_month[curr_month];
                curr_day = 0;
            }
            days_left_in_month--;
            days_total--;
            curr_day++;
        }

        curr_day++;     // due to it began with 0

        // add time to dst
        int mins = (*when / 60) % 60;
        char mins_str[3] = {'\0'};
        ft_int_to_str(mins_str, mins, 2);

        int hours = (*when / 3600) % 24;
        char hours_str[3] = {'\0'};
        ft_int_to_str(hours_str, hours, 2);

        char time_str[5] = {'\0'};
        ft_strcpy(time_str, hours_str);
        ft_strcpy(time_str+2, ":");
        ft_strcpy(time_str+3, mins_str);

        int dst_cursor = 0;
        ft_strcpy(dst, days[curr_day_of_the_week]);
        dst_cursor = dst_cursor + ft_strlen(days[curr_day_of_the_week]);

        ft_strcpy(dst+dst_cursor, " ");
        dst_cursor++;

        ft_strcpy(dst+dst_cursor, months[curr_month]);
        dst_cursor = dst_cursor + ft_strlen(months[curr_month]);

        ft_strcpy(dst+dst_cursor, " ");
        dst_cursor++;

        // add curr_day
        char *str_curr_day = ft_int_to_str_malloc(curr_day);
        ft_strcpy(dst+dst_cursor, str_curr_day);
        dst_cursor = dst_cursor + ft_strlen(str_curr_day);
        free(str_curr_day);

        ft_strcpy(dst+dst_cursor, " ");
        dst_cursor++;

        // TODO: add time_str
        ft_strcpy(dst+dst_cursor, time_str);

        (void)curr_day_of_the_week;

        break;
    }
    }

    return 1;
}

int list(struct utmp *p, time_t logout_time, int what){

    char logouttime[32] = {'\0'};    // str to store logout time
    char logintime[32] = {'\0'};     // str to store login time
    char length[32] = {'\0'};
    char final[512] = {'\0'};        // final str to print

    struct last_timefmt *fmt;
    time_t utmp_time, secs;
    int mins, hours, days;

    fmt = &short_fmt;
    utmp_time = p->ut_tv.tv_sec;

    /* log-out time */
    secs = logout_time - utmp_time;
    mins = (secs / 60) % 60;
    hours = (secs / 3600) % 24;
    days = secs / 86400;

    // put time in "in" format to logintime

    time_formatter(fmt->in_fmt, logintime, &utmp_time);
 
    // put time in "out" format to logouttime
    if (*logouttime){
        ft_strcpy(logouttime, "- ");
        time_formatter(fmt->out_fmt ,logouttime+2, &logout_time);
    }

    if (logout_time == currentdate){
        ft_strcpy(logouttime+2, "  still running");
    } else if (days) {
        // add days to logouttime
    } else if (hours) {
        // add hours to logouttime
    } else {
        // add mins to logouttime
    }

    switch(what) {
        // normal user-process, still logged in
        case R_NOW:
            ft_strcpy(logouttime, "   still");
            ft_strcpy(length, "logged in");
            break;
    }

    // printing out the FINAL line
    ft_strcat(final, p->ut_user);
    ft_strcat(final, "   ");
    ft_strcat(final, p->ut_line);
    ft_strcat(final, "   ");
    ft_strcat(final, p->ut_host);
    ft_strcat(final, " ");
    ft_strcat(final, logintime);
    ft_strcat(final, logouttime);
    ft_strcat(final, " ");
    ft_strcat(final, length);
    ft_strcat(final, "\n");
    ft_putstr(final);



    (void)what;
    (void)fmt;
    (void)secs;
    (void)mins;
    (void)hours;
    (void)days;

    return 0;

}

int process_wtmp_file(){

    int quit = 0;       // flag for while cycle

    struct utmp ut;                         // current utmp entry
    struct utmplist *ulist = NULL;        // all entries
    struct utmplist *p;                     // pointer to ulist
    struct utmplist *next;                  // pointer to next of ulist
    int size_utmp = sizeof(struct utmp);    // size of utmp struct

    time_t begintime;       // when wtmp begins
    time_t lastboot = 0;    // last boot time
    time_t lastdown;        // last downtime
    time_t lastrch;         // last run level change
    int whydown = 0;

    int c;

    time(&lastdown);

    lastdate = currentdate = lastrch = lastdown;

    int fd = open("/var/log/wtmp", O_RDONLY);
    if (fd == -1){
        // TODO: print the actual errno
        return -1;
    }

    // Read first structure to capture begintime
    if (read(fd, &ut, size_utmp) <= 0){
        // the file is empty or error happen
        // TODO: print the actual errno
        return -1;
    }

    begintime = ut.ut_tv.tv_sec;

    // go to the end of file minus one structure and start reading
    // wtmp
    lseek(fd, -size_utmp, SEEK_END);

    while (!quit){
        // cycle-begin: reading new utmp entry
        if (read(fd, &ut, size_utmp) <= 0){
            break;
        }

        // TODO: cycle-main-part:
        ft_putnbr(ut.ut_type);
        ft_putstr(" ");
        ft_putstr(ut.ut_user);
        ft_putstr(" ");
        ft_putstr(ut.ut_host);
        ft_putstr(" ");
        char time_str[80];
        time_t epoch_time = ut.ut_tv.tv_sec;
        struct tm *timeinfo = localtime(&epoch_time);
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);
        ft_putstr(time_str);
        ft_putstr("\n");

        lastdate = ut.ut_tv.tv_sec;

        if ((ft_strcmp(ut.ut_line, "~") == 0) && (ft_strcmp(ut.ut_user, "shutdown") == 0)){
            ut.ut_type = SHUTDOWN_TIME; 
        }

        switch (ut.ut_type)
        {
        case SHUTDOWN_TIME:
            ft_strcpy(ut.ut_line, "system down");
            quit = list(&ut, lastboot, R_NORMAL);
            break;

        case BOOT_TIME:
            // TODO: finish the case
            lastboot = ut.ut_tv.tv_sec;
            break;

        case RUN_LVL:
            break;

        case USER_PROCESS:
            c = 0;
            for (p = ulist; p; p = next){
                next = p->next;
                // TODO: finish work with ulist
            }

            if (c == 0) {
                if (!lastboot){
                    c = R_NOW;
                }
                else {
                    c = whydown;
                }
                quit = list(&ut, lastboot, c);
            }

            break;

        case DEAD_PROCESS:
            break;
        
        default:
            ft_putstr("unrecognized ut_type: ");
            ft_putnbr(ut.ut_type);
            ft_putstr("\n");
            break;
        }

        // cycle-end: checking if returning utmp 
        if (lseek(fd, -2*size_utmp, SEEK_CUR) == 0){
            break;
        }
    }

    (void)begintime;

    return 1;
}


int main(){

    int res = process_wtmp_file();

    // TODO: process the res and handle errors

    (void)res;

    return (0);
}
