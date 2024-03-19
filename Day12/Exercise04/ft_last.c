#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <utmp.h>

int main(){

    struct utmp ut;
    int size_utmp = sizeof(struct utmp);

    int fd = open("/var/log/wtmp", O_RDONLY);
    if (fd == -1){
        // TODO: print the actual errno
        return -1;
    }

    while (read(fd, &ut, size_utmp) > 0){
        int a = 1;
        (void)a;
    }

    return (0);
}
