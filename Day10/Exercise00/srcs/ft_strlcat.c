#include "libft.h"

/*
int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}
*/

unsigned int ft_strlcat(char *dest, char *src, unsigned int size) {
    // size is size (not len, len is used part, size is allocated size) of dest
    int dest_filled_part_len = ft_strlen(dest);

    int i;

    for (i=0; src[i]!='\0' && (dest_filled_part_len+i)<size-1; i++) {
        dest[dest_filled_part_len+i] = src[i];
    }

    // strlcat is guaranteed to end dest with \0
    dest[i] = '\0'; 

    return i;
}