#include <unistd.h>

void	ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}

void ft_print_numbers()
{
	int n_1_in_ascii = 48;
	int n_9_in_ascii = 57;
	for (int i=n_1_in_ascii; i<n_9_in_ascii+1; i++)
	{
		char ch = i;
		ft_putchar(ch);
	}
}

int main(void)
{
	ft_print_numbers();
	return 0;
}
