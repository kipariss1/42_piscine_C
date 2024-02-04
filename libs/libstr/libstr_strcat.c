#include "libstr.h"

char* my_strcat(char *dest, char *src) {
    int size_of_dest = my_strlen(dest);

    int i;

    for (i=0; src[i] != '\0'; i++) {
        dest[size_of_dest+i] = src[i];
    }
    dest[size_of_dest+i] = '\0';

    return dest;
}