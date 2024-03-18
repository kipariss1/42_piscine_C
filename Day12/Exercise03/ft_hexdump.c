#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"

char *base_from = "0123456789";
char *base_to = "0123456789abcdef";

int get_file_size(int fd){
    lseek(fd, 0, SEEK_SET);
    int res = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    return res;
}

void put_hex_to_template(char *hex, char *template){

    int len_hex = ft_strlen(hex);
    int len_template = ft_strlen(template);


    for (len_hex--, len_template--; len_hex >= 0 && len_template >= 0; len_hex--, len_template--){
        template[len_template] = hex[len_hex];
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

    int curr_char;
    int byte_counter = 0;
    int row_counter = 0;
    int first_time = 1;
    int size_of_file = get_file_size(fd);
    int curr_offset = 0;
    int read_bytes;
    int only_one_odd_byte_left = 0;

    int line_len = 78;
    int char_num = 16;

    int line_number = size_of_file/char_num + 1;
    int begin_of_bytes = 10; 
    int begin_of_text = 60;
    int end_of_text = 75;
    
    char buff[line_number][line_len+1];
    // putting '|' and row nbr in template
    for (int i = 0; i<line_number; i++){

        buff[i][begin_of_text-1] = '|';
        buff[i][end_of_text+1] = '|';
        buff[i][line_len-1] = '\n';
        buff[i][begin_of_bytes-1] = ' ';
        buff[i][begin_of_bytes-2] = ' ';
        buff[i][line_len+1] = '\0';

        char *str_byte_counter = ft_int_to_str_malloc(i*0x10);
        char *row_nbr = ft_convert_base(str_byte_counter, base_from, base_to);
        char template[] = "00000000";
        put_hex_to_template(row_nbr, template);

        for (int j = 0; template[j]!='\0'; j++){
            buff[i][j] = template[j];
        }
 
    }

    int line_offset_for_bytes = 0;
    while (1){

        read_bytes = read(fd, &curr_char, 1);
        if (read_bytes<=0){
            break;
        }
        curr_offset = curr_offset + read_bytes;

        if (!(byte_counter%0x10)){
            line_offset_for_bytes = 0;
        }

        buff[byte_counter/0x10][begin_of_text + byte_counter%0x10] = (char)curr_char;  

        char *str_curr_char = ft_int_to_str_malloc(curr_char);
        char *convtd_curr_char = ft_convert_base(str_curr_char, base_from, base_to);
        char template[] = "00";
        put_hex_to_template(convtd_curr_char, template);

        buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = template[0]; 
        buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = template[1]; 
        buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = ' ';
        if (byte_counter%0x10 == 7){
            buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = ' ';
        }

        free(convtd_curr_char);
        free(str_curr_char);

        byte_counter++;
    }

    while (!(byte_counter%0x10)){

        buff[byte_counter/0x10][begin_of_text + byte_counter%0x10] = ' ';

        buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = ' '; 
        buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = ' '; 
        buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = ' ';
        if (byte_counter%0x10 == 7){
            buff[byte_counter/0x10][begin_of_bytes + line_offset_for_bytes++] = ' ';
        }

        byte_counter++;
    }

    for (int i=0; i<line_number; i++){
        ft_putstr(buff[i]);
    }
    
    (void)byte_counter;
    (void)curr_char;
    (void)row_counter;
    (void)first_time;
    (void)size_of_file;
    (void)curr_offset;
    (void)read_bytes;
    (void)only_one_odd_byte_left;

    (void)line_len;

    (void)line_number;
    (void)begin_of_bytes; 
    (void)begin_of_text;
    (void)end_of_text;
    (void)buff;

    return;
}

// template: 00000000  4c 6f 72 65 6d 20 49 70  73 75 6d 20 69 73 20 73  |Lorem Ipsum is s| 

void hexdump(char *file){

    int fd = check_file(file);

    int curr_char;
    int byte_counter = 0;
    int row_counter = 0;
    int first_time = 1;
    int size_of_file = get_file_size(fd);
    int curr_offset = lseek(fd, 1, SEEK_SET);
    int read_bytes;
    int only_one_odd_byte_left = 0;
    
    while (1){
        read_bytes = read(fd, &curr_char, 1);
        if (read_bytes<=0){
            break;
        }
        curr_offset = curr_offset + read_bytes;
        if (!(byte_counter%0x10)){
            if (!first_time){
                ft_putstr("\n");
            }
            else {
                first_time = 0;
            }

            row_counter = byte_counter;
            char *str_byte_counter = ft_int_to_str_malloc(row_counter);
            char *row_nbr = ft_convert_base(str_byte_counter, base_from, base_to);
            char template[] = "00000000";
            put_hex_to_template(row_nbr, template);
            ft_putstr(template);
            // free(str_byte_counter);
            // free(row_nbr);
        }
        if (!(byte_counter%0x02)){
            ft_putstr(" ");
            if (only_one_odd_byte_left){
                ft_putstr("00");
            }
        }
        // putting byte read, from file
        char *str_curr_char = ft_int_to_str_malloc(curr_char);
        char *convtd_curr_char = ft_convert_base(str_curr_char, base_from, base_to);
        char template[] = "00";
        put_hex_to_template(convtd_curr_char, template);
        ft_putstr(template);

        free(convtd_curr_char);
        free(str_curr_char);

        // breaking here if only one odd byte left and it's handled
        if (only_one_odd_byte_left){
            byte_counter++;
            break;
        }

        // handling the offset to mimic little endian
        if (byte_counter%0x02){
            if ((size_of_file-curr_offset)>2){
                curr_offset = lseek(fd, 2, SEEK_CUR);
            }
            else{       // if we reached the end of file and there is no space to move offset 2 chars away -> move 1 char away 
                curr_offset = lseek(fd, 1, SEEK_CUR);
                only_one_odd_byte_left = 1;
            }
        }
        else {
            curr_offset = lseek(fd, -2, SEEK_CUR);
        }

        byte_counter++;
    }       

    // putting the last 16 empty bytes in the end
    int empty_lines = ++byte_counter + 0x10;
    while (byte_counter<empty_lines){
        if (!(byte_counter%0x10)){
            ft_putstr("\n");
            char *str_byte_counter = ft_int_to_str_malloc(row_counter+0xf);
            char *row_nbr = ft_convert_base(str_byte_counter, base_from, base_to);
            char template[] = "00000000";
            put_hex_to_template(row_nbr, template);
            ft_putstr(template);
            // free(str_byte_counter);
            // free(row_nbr);
        }
        if (!(byte_counter%0x02)){
            ft_putstr(" ");
        }
        ft_putstr("  ");
        byte_counter++;
         
    }

    ft_putstr("\n");

    (void)curr_offset;
    (void)size_of_file;
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

