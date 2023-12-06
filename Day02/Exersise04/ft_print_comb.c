#include <unistd.h>

void ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}

void int_num_to_char_arr(int num, char res_char_arr[], int num_len)
{
	int ascii_offset = 48;

	int devided_num[3] = {num/100, num%100/10, num%10};

	for (int i; i<num_len; i++) {
		res_char_arr[i] = devided_num[i] + ascii_offset; 
	}	
}

void print_char_arr_by_one(char res_char_array[], int num_len)
{

	for (int i=0; i<num_len; i++)
	{
		ft_putchar(res_char_array[i]);		
	}

}

void ft_print_comb(void)
{
	char res_char_arr[3];
	int num_len = 3;
	int in_val = 358;

	int_num_to_char_arr(in_val, res_char_arr, num_len);
	print_char_arr_by_one(res_char_arr, num_len);
	// TODO: finish make algorithm for printing non repeating characters!
		
}

int main(void)
{
	ft_print_comb();
	return 0;
}
