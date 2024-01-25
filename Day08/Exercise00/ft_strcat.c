#include "ft_strlen.h"

/*
int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}
*/

char* ft_strcat(char *dest, char *src) {
    int size_of_dest = ft_strlen(dest);

    int i;

    for (i=0; src[i] != '\0'; i++) {
        dest[size_of_dest+i] = src[i];
    }
    dest[size_of_dest+i] = '\0';

    return dest;
}