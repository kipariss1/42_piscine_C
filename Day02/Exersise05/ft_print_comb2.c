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

void ft_print_comb2(void)
{
	int num_len = 5;
	char res_char_arr[num_len];
	int ascii_offset = 48;

	res_char_arr[2] = 32; 	// entering space inbetween the digits
	
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			if (j>i) {
				if ((i/10)>0) {
					res_char_arr[0] = i/10 + ascii_offset;
				}
				else {
					res_char_arr[0] = ascii_offset;
				}
				res_char_arr[1] = i%10 + ascii_offset;
				if ((j/10)>0) {
					res_char_arr[3] = j/10 + ascii_offset;
				}
				else {
					res_char_arr[3] = ascii_offset;
				}
				res_char_arr[4] = j%10 + ascii_offset;

				print_char_arr_by_one(res_char_arr, num_len);
			}
		}
	}
}

int main(void)
{
	ft_print_comb2();
	return 0;
}
