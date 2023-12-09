#include <unistd.h>

int ascii_offset = 48;

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

long long int my_pow(int digit, int degree) {
	
	if (degree == 0) {
		return 1;
	}

	long long int outP = digit;

	while (degree != 1) {
		outP = outP*digit;
		degree -= 1;
	}

	return outP;
}

int make_char_arr_and_check_uniq(char empty_char_arr[], int len_of_arr, long long int num_to_put) {	
	long long int copy_of_num = num_to_put;
	// putting number in the empty char array	
	int i = 0;
	while (copy_of_num != 0) {
		empty_char_arr[(len_of_arr-1)-i] = copy_of_num%10 + ascii_offset;
		copy_of_num = copy_of_num/10;
		i++;	
	}
	// if empty char array is not fully filled, putting zeros in the free spaces
	int diff;
	if (i != (len_of_arr)) {
		diff = (len_of_arr) - i;
		for (int j=0; j<diff; j++) {
			empty_char_arr[j] = 0 + ascii_offset;
		}
	}	
	// checking if array has different numbers and less signigicant numbers are greater, than all their neighbours on the left
	int is_unique = 1; 
	int check_all = 0;
	if (empty_char_arr[0] != ascii_offset) {check_all=1;}
	for (int i=1; i<len_of_arr; i++){
		if ((empty_char_arr[i] != ascii_offset) || (check_all == 1)) {
			check_all = 1;
			for (int j=i-1; j != -1; j--){
				if (empty_char_arr[j] >= empty_char_arr[i]){is_unique = 0;}
			}
		}	
	}

	return is_unique;	
}	

void ft_print_combn(int n)
{
	char char_res_array[n];
	for (int j=0; j<n; j++) {
		char_res_array[j] = '\0';
	}

	long long int range = my_pow(10, n);
	int stop_cond = 0;

	for (long long int i=0; i<range; i++) {
		// break if stop condition fulfilled
		if (stop_cond == 1){break;}

		// DO MAIN WORK: split the number by digits, put into char arr, check uniqueness
		int is_unique = make_char_arr_and_check_uniq(char_res_array, n, i);
		if (is_unique == 1) {
			print_char_arr_by_one(char_res_array, n);			
		}
		// checking for stop condition
		int iter = 0;
		stop_cond = 1;
		for (int k=n-1; k>-1; k--) {
			if (char_res_array[k] != ((9 - iter) + ascii_offset)){
				stop_cond=0;
			}
			iter++; 
		}

		// clearing char array
		for (int j=0; j<n; j++) {
			char_res_array[j] = '\0';
		}
	}	
}

int main(void)
{
	ft_print_combn(9);
	return 0;
}
