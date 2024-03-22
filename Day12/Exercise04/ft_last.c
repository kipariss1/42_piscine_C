#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <utmp.h>
#include "libft.h"

int main(){

    struct utmp ut;
    int size_utmp = sizeof(struct utmp);

    int fd = open("/var/log/wtmp", O_RDONLY);
    if (fd == -1){
        // TODO: print the actual errno
        return -1;
    }

    while (read(fd, &ut, size_utmp) > 0){
        ft_putstr(ut.ut_user);
        ft_putstr(" ");
        ft_putstr(ut.ut_host);
        ft_putstr(" ");
        ft_putstr("\n");
    }
    ft_putstr("\n");

    return (0);
}
