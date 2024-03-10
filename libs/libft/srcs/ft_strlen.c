#include "libft.h"

int ft_strlen(char *str){

	int count;

	for (count = 0; str[count]!='\0'; count++){}

	return count;

}

