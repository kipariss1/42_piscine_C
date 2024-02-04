#include "libstr.h"

char* my_strncat(char *dest, char *src, int n) {

    int len_dest = my_strlen(dest);

    int i;

    for (i=0; src[i]!='\0' && i<n; i++) {
        dest[len_dest + i] = src[i];
    }

    dest[len_dest + i] = '\0';

    return dest;
}