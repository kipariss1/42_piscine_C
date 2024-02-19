#include "libft.h"

int ft_str_to_int(char *str){

    int is_negative;
    if (str[0]=='-'){
        is_negative = 1;
    }
    else {
        is_negative = 0;
    }

    int len_str;
    for (len_str=1; str[len_str]!='\0'; len_str++){}

    int ascii_offset = 48;
    int res = 0;

    int i;
    if (is_negative){
        i = 1;
    }
    else {
        i = 0;
    }

    for (; str[i]!='\0'; i++){
        int digit  = str[i] - ascii_offset;
        res = res + digit*ft_iterative_power(10, len_str-1-i);
    }

    if (is_negative){
        return res*-1;
    }

    return res;
}
