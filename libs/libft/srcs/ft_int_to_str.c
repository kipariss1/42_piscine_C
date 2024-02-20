#include "libft.h"

void ft_int_to_str(char *buffer, int convert_from, int len_convert_from){
    int ascii_offset = 48;
    for (int i=0; i<len_convert_from; i++){
        buffer[len_convert_from-1-i] = (convert_from%10) + ascii_offset;
        convert_from = convert_from/10;
    }
}