#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <utmp.h>
#include "libft.h"


int process_wtmp_file(){

    int quit = 0;       // flag for while cycle

    struct utmp ut;                         // current utmp entry
    int size_utmp = sizeof(struct utmp);    // size of utmp struct

    time_t begintime;       // when wtmp begins

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
 

        // cycle-end: checking if returning utmp 
        if (lseek(fd, -2*size_utmp, SEEK_CUR) == 0){
            break;
        }
    }

    (void)begintime;

    return 1;
}


int main(){

    process_wtmp_file();

    return (0);
}
