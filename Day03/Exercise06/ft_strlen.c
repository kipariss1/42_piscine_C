#include <unistd.h>

void ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}


int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}

void main(){

	char str[] = "huy";
	int len_str = ft_strlen(str);
	int ascii_offset = 48;
	ft_putchar(len_str + ascii_offset);

}
