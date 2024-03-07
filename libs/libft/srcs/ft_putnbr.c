#include "libft.h"

// #include <unistd.h>

// void ft_putchar(char c)
// {
//  // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
//   write(1, &c, 1);
// }


void print_char_arr_by_one(char res_char_array[], int num_len)
{

	for (int i=0; i<num_len; i++)
	{
		ft_putchar(res_char_array[i]);		
	}

}

void ft_putnbr(int n)
{
	int is_negative = 0;

	if (n<0) {
		is_negative = 1;
		n = n*-1;
	}

	int copy_n = n;
	int len_of_int_n = 0; 
	int ascii_offset = 48;

	while (copy_n/10 != 0) {
		len_of_int_n += 1;
		copy_n = copy_n/10;
	}

	char char_res_arr[len_of_int_n+1];

	int curr_digit;

	for (int i = 0; i<len_of_int_n+1; i++) {
		char_res_arr[len_of_int_n-i] = n%10 + ascii_offset;
		n = n/10;	
	}

	if (is_negative != 0) {
		ft_putchar('-');	
	}

	(void)curr_digit;

	print_char_arr_by_one(char_res_arr, len_of_int_n+1);

}

// int main(void)
// {
// 	ft_putnbr(25);
// 	ft_putnbr(-96); 
// 	ft_putnbr(1000); 
// 	return 0;
// }
