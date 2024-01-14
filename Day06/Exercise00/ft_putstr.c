#include <unistd.h>

void	ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}


void ft_putstr(char *str){

	for (int i=0; *(str+i) != '\0'; i++){
		ft_putchar(*(str+i));
	}

}
