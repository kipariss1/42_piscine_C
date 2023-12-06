#include <unistd.h>

void	ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}

void ft_print_alphabet()
{
	int n_a_in_ascii = 97;
	int n_z_in_ascii = 122;
	for (int i=n_z_in_ascii; i>n_a_in_ascii-1; i--)
	{
		char ch = i;
		ft_putchar(ch);
	}
}

int main(void)
{
	ft_print_alphabet();
	return 0;
}
