#include "libft.h"


void ft_initstr(char *str, unsigned int strlen) {
    for (int i=0; i<strlen; i++){str[i]='\0';}
}