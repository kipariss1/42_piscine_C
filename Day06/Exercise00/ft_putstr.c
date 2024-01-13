#include "ft_putchar.h"

void ft_putstr(char *str){

	for (int i=0; *(str+i) != '\0'; i++){
		ft_putchar(*(str+i));
	}

}
