#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

int add_filenames_flag;

int check_file(char *file_path){
    int fd = open(file_path, O_RDONLY);

    if (fd == -1){
        ft_putstr("\nproblem with openning of the file: ");
        ft_putstr(file_path);
        ft_putstr("\n");
        ft_putstr(" ; errno = ");
        ft_putnbr(errno);
        ft_putstr("\n");
    }

    return fd;
}

void tail_bytes(char *file_path, int bytes){

    int fd = check_file(file_path);

    if (fd == -1){
        return;
    }

    if (add_filenames_flag){
        ft_putstr("==>");
        ft_putstr(file_path);
        ft_putstr("<==\n");
    }

    lseek(fd, bytes*-1, SEEK_END);

    char curr_char;
    while (read(fd, &curr_char, 1)>0){
        write(1, &curr_char, 1);
    }

    close(fd);

    return;
}

void tail(char *file_path){

    int fd = check_file(file_path);

    if (fd == -1){
        return;
    }

    if (add_filenames_flag){
        ft_putstr("==>");
        ft_putstr(file_path);
        ft_putstr("<==\n");
    }

    // search for 10th row from the end and moving offset there
    int not_found_rows = 10;
    lseek(fd, -1, SEEK_END);     // set file offset to the end of file - 1
    char curr_char;
    int first_time = 1;
    while (not_found_rows > 0){
        read(fd, &curr_char, 1);
        if (curr_char == '\n' && !first_time){
            not_found_rows--;
        }

        if (first_time){
            first_time = 0;   
        } 

        if (lseek(fd, -2, SEEK_CUR) == -1){     // set the file offset "-2", so when it reads 1 char, it would remain "-1" 
            lseek(fd, -1, SEEK_CUR);            // just in case try to move offset also -1
            break;
        }
    }
    
    // tailing
    first_time = 1;
    while (read(fd, &curr_char, 1)>0){
        if (first_time && ((curr_char == '\n') || (curr_char == ' ') || (curr_char == '\0'))){
            continue;
        }
        write(1, &curr_char, 1);
        first_time = 0;
    }

    close(fd);

    return;
}

int main(int argc, char *argv[]){

    if (argc == 1){
        // Maybe here the reading of the standard output will be needed
        ft_putstr("No file specified");
        ft_putstr("\n");
    }

    // taking care of bytes argument
    int bytes_mode = -1;
    int bytes_mode_flag_arg_pos = -1;
    int n_of_files = 0;
    for (int i=1; argv[i]!=0x00; i++){
        if (!ft_strcmp(argv[i], "-c") || !ft_strcmp(argv[i], "--bytes")) {
            bytes_mode = 1; 
            bytes_mode_flag_arg_pos = i;
        }
        else {
            n_of_files++;
        }
    }

    if (bytes_mode==1){
        n_of_files--;   // "--n_of_files" because n_of_files also includes bytes to print
    }

    add_filenames_flag = (n_of_files>1) ? 1 : 0; 
    int n_of_bytes = 0;
    if (bytes_mode == 1){ 
        if (!ft_str_is_numeric(argv[bytes_mode_flag_arg_pos+1])){
            ft_putstr("Invalid number of bytes: ");
            ft_putstr(argv[bytes_mode_flag_arg_pos+1]);
            ft_putstr("\n");
            return (-1);
        }
        n_of_bytes = ft_str_to_int(argv[bytes_mode_flag_arg_pos+1]); 
    }

    // Doing tailing here:
    for (int i=1; argv[i]!=0x00; i++){
        if (i == bytes_mode_flag_arg_pos || i == (bytes_mode_flag_arg_pos+1)){
            continue;
        }

        if (bytes_mode != -1){
            // tail file with -c flag
            tail_bytes(argv[i], n_of_bytes);
        }
        else {
            // tail file regularly
            tail(argv[i]);
        }

        // TODO: fix this, argc will be lowering automatically
        if (i<--argc){
            ft_putstr("\n");
        }

    }

    (void)n_of_bytes;
    (void)bytes_mode;
    (void)bytes_mode_flag_arg_pos;

    return (0);
}
