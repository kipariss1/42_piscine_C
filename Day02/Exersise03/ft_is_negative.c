#include <unistd.h>

void	ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}

void ft_is_negative(int n)
{
	char outpt;
	if (n<0)
	{
		outpt = 'N';
	}
	else
	{
		outpt = 'P';
	}
	ft_putchar(outpt);
	
}

int main(void)
{
	ft_is_negative(-1);
	ft_is_negative(-10);
	ft_is_negative(15);
	return 0;
}
