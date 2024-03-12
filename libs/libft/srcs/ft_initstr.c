#include "libft.h"

void ft_initstr(char *str, unsigned int strlen) {
    int i;
    for (i=0; i<strlen && str[i]!='\0'; i++){str[i]='\0';}
    str[i]='\0';
}