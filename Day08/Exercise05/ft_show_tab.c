#include "ft_stock_par.h"
#include <stdlib.h>

void print_char_arr_by_one(char res_char_array[], int num_len)
{

	for (int i=0; i<num_len; i++)
	{
		ft_putchar(res_char_array[i]);		
	}

	ft_putchar(',');
	ft_putchar(' ');


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
	print_char_arr_by_one(char_res_arr, len_of_int_n+1);

}

struct s_stock_par* ft_params_to_tab(int ac, char **av){

    t_stock_par *res = (t_stock_par*)malloc((ac+1)*sizeof(t_stock_par));

    int i;
    // assigning parameters to structure
    for (i=0; i<ac; i++){
        // getting length
        int j;
        for (j=0; av[i][j]!='\0'; j++){}
        res[i].size_param = j;
        // getting pointer to argument
        res[i].str = av[i];
        // making copy of argument
        res[i].copy = (char*)malloc(j*sizeof(char));
        for (int k=0; av[i][k]!='\0'; k++){res[i].copy[k] = av[i][k];}
        // splitting str by whitespaces
        res[i].tab = ft_split_whitespaces(av[i]);
    }

    res[i].str = NULL;  // closing the array of t_stock_par's

    return res;  
}

void ft_show_tab(struct s_stock_par *par){
    for (int i=0; par->copy[i]!='\0'; i++){ft_putchar(par->copy[i]);}
    ft_putchar('\n');
    ft_putnbr(par->size_param);
    ft_putchar('\n');
    for (int i=0; par->tab[i]!=NULL; i++){
        for (int j=0; par->tab[i][j]!='\0'; j++){ft_putchar(par->tab[i][j]);}
        ft_putchar('\n');
    }
}

int main(int argc, char **argv){

    t_stock_par *res;

    res = ft_params_to_tab(argc, argv);
    for (int i=0; res[i].str != NULL; i++){
        ft_show_tab(&res[i]);
    }

    return (0);
}

