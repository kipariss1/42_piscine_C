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

void ft_print_comb(void)
{
	char res_char_arr[3];
	int num_len = 3;
	int ascii_offset = 48;

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if ((j != i) && (j>i)) {
				for (int k=0; k<10; k++) {
					if ((k != j) && (k != i) && (k>j)) {
						res_char_arr[0] = i+ascii_offset;
						res_char_arr[1] = j+ascii_offset;
						res_char_arr[2] = k+ascii_offset;
						print_char_arr_by_one(res_char_arr, num_len);
					}
				}
			}
		}
	}

		
}

int main(void)
{
	ft_print_comb();
	return 0;
}
