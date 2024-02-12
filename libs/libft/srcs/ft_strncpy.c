#include "libft.h"

char* ft_strncpy(char* dest, char* src, unsigned int n) {
    int i;

    for (i=0; (src[i]!='\0') && (i<n); i++) {
        dest[i] = src[i];
    }  
    for (;i<=n; i++) {
        dest[i] = '\0';
    }

    return dest; 
}