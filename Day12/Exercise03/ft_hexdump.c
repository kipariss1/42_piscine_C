#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

char *base_from = "0123456789";
char *base_to = "0123456789abcdef";

void ft_put_rownbr_to_template(char *row_nbr, char *template){

    int len_row_nbr = ft_strlen(row_nbr);
    int len_template = ft_strlen(template);


    for (len_row_nbr--, len_template--; len_row_nbr >= 0 && len_template >= 0; len_row_nbr--, len_template--){
        template[len_template] = row_nbr[len_row_nbr];
    } 

    return;
}

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

void hexdump_canonical(char *file){

    int fd = check_file(file);

    (void)fd;

    return;
}

void hexdump(char *file){

    int fd = check_file(file);

    int curr_char;
    int byte_counter = 0;
    int first_time = 1;
    while (read(fd, &curr_char, 1)>0){
        if (!(byte_counter%0x10)){
            if (!first_time){
                ft_putstr("\n");
            }
            else {
                first_time = 0;
            }
            char* row_nbr = ft_convert_base(ft_int_to_str_malloc(byte_counter), base_from, base_to);
            char template[] = "00000000";
            ft_put_rownbr_to_template(row_nbr, template);
            ft_putstr(template);
            ft_putstr(" ");
        }
        if (!(byte_counter%0x02)){
            ft_putstr(" ");
        }
        // putting byte read, from file
        // TODO: somehow fix the freeing of allocated space
        ft_putstr(ft_convert_base(ft_int_to_str_malloc(curr_char), base_from, base_to));

        byte_counter++;
    }       

    ft_putstr("\n"); 

    return;
}

int main(int argc, char *argv[]){

    if (argc == 1){
        ft_putstr("The file for display is not specified!");
        return (-1);
    }

    // taking care of -C/--canonical argument
    int is_canonic_mode = 0;
    int pos_of_canonic_arg = 0;
    for (int i=1; i<argc; i++){
        if (!ft_strcmp(argv[i], "-C") || !ft_strcmp(argv[i], "--canonical")){
            is_canonic_mode = 1;
            pos_of_canonic_arg = i;
            break;
        }
    }

    // doing main work of hexdump here
    for (int i=1; i<argc; i++){
        if (is_canonic_mode && (pos_of_canonic_arg == i)){
            continue;   // skipping the "-C"/"--canonical" argument
        }

        if (is_canonic_mode){
            hexdump_canonical(argv[i]);
        }
        else {
            hexdump(argv[i]);
        }

    }

    return (0);
}

