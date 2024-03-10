#include "libft.h"
#include <stdlib.h>

char* ft_int_to_str_malloc(int convert_from){

    if (convert_from == 0){
        return "0";
    }

    int is_negative = 0;
    if (convert_from<0){
        convert_from = convert_from*-1;
        is_negative = 1;
    }

    int cpy =convert_from;
    int len_of_int = 0;
    while (cpy>0){
       len_of_int++;
       cpy = cpy/10; 
    }

    if (is_negative){
        len_of_int++;
    }

    char *res = (char*)malloc(len_of_int*sizeof(char));

    int ascii_offset = 48;
    for (int i=0; i<len_of_int; i++){
        res[len_of_int-1-i] = (convert_from%10) + ascii_offset;
        convert_from = convert_from/10;
    }

    if (is_negative){
        res[0] = '-';
    }

    return res;
}

// int main() {

//     int a = 234;

//     char* res = ft_int_to_str_malloc(a);

//     return (0);
// }
