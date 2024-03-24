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
char *months[] = {"January", "February", "March", "April", "May", "June", 
                    "July", "August", "September", "October", "November", "December"};
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int initial_year = 1970;

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
long long int lastdate;

int time_formatter(int fmt, char *dst, time_t *when){

    switch (fmt)
    {
    case LAST_TIMEFTM_HHMM:
        // convert "when" time to "- 20:27" format
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

    case LAST_TIMEFTM_CTIME:
        // convert "when" time to "Sat Mar 23 20:27" fmt
        int days_total = *when / 86400;
        int curr_day_of_the_week = days_total%7;

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

        // TODO: add curr day, month, day of month to dst
        // TODO: add time to dst

        (void)curr_day_of_the_week;

        break;
    }

    return 1;
}

int list(struct utmp *p, time_t logout_time, int what){

    char logouttime[32] = {'\0'};    // str to store logout time
    char logintime[32] = {'\0'};     // str to store login time

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

    ft_strcpy(logouttime, "- ");
    // put time in "out" format to logouttime
    time_formatter(fmt->out_fmt ,logouttime+2, &logout_time);

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
    int size_utmp = sizeof(struct utmp);    // size of utmp struct

    time_t begintime;       // when wtmp begins
    time_t lastboot = 0;    // last boot time

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
