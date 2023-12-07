#include <unistd.h>

void ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}


void print_char_arr_by_one(char res_char_array[], int num_len)
{

	for (int i=0; i<num_len; i++)
	{
		ft_putchar(res_char_array[i]);		
	}

	ft_putchar(',');
	ft_putchar(' ');


}

int my_pow(int digit, int degree) {
	
	if (degree == 0) {
		return 1;
	}

	while (degree != 1) {
		digit *= digit;
		degree -= 1;
	}

	return digit;
}

// default range is equal to zero
// n - number, that needs to be printed
// range - the range of string in which n needs to be printed
// e.g. (n = 1, range = 1, output: '1';
// 	 n = 1, range = 4, output: '0001';)
void ft_putnbr(int n, int range)
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

	int diff = range - (len_of_int_n + 1);

	char char_res_arr[len_of_int_n+1];

	int curr_digit;

	for (int i = 0; i<len_of_int_n+1; i++) {
		char_res_arr[len_of_int_n-i] = n%10 + ascii_offset;
		n = n/10;	
	}

	if (is_negative != 0) {
		ft_putchar('-');	
	}
	for (int i = 0; i<diff; i++) {
		ft_putchar('0');	
	}
	print_char_arr_by_one(char_res_arr, len_of_int_n+1);

}

void ft_print_combn(int n)
{
	char char_res_array[n];

	int range = my_pow(10, n); 
	for (int i=1; i<range; i++) {
		// TODO: check if number is unique
		ft_putnbr(i, n);
	}
}

int main(void)
{
	ft_print_combn(2);
	//ft_print_combn(0);
	//TODO: fix not working for n=10
	//ft_print_combn(10);
	return 0;
}
