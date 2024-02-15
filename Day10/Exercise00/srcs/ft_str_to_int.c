#include "libft.h"

int ft_str_to_int(char *str){

    int len_str;
    for (len_str=1; str[len_str]!='\0'; len_str++){}

    int ascii_offset = 48;
    int res = 0;

    for (int i=0; str[i]!='\0'; i++){
        int digit  = str[i] - ascii_offset;
        res = res + digit*ft_iterative_power(10, len_str-1-i);
    }

    return res;
}
