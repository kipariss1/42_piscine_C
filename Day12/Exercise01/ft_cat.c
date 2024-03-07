#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

void read_and_print_file(char *filepath){

    int fd = open(filepath, O_RDONLY);

    if (fd == -1){
        ft_putstr(" There is error with opening of the file, errno = ");
        ft_putnbr(errno);
        ft_putstr(" ");
        return;
    }

    char curr_char;
    while (read(fd, &curr_char, 1)>0){
        write(1, &curr_char, 1);
    }
    
    return;
}

int main(int argc, char *argv[]){

    if (argc == 1){
        // Maybe read of the standard input should be implemented here
        write(1, "No files selected to catinate \n", 31);
    }

    for (int i = 1; i<argc; i++){
       read_and_print_file(argv[i]); 
    }    

    ft_putstr("\n");

    return (0);
}
