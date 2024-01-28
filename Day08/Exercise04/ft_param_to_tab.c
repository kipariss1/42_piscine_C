#include "ft_stock_par.h"
#include <stdlib.h>

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

int main(int argc, char **argv){

    t_stock_par *res;

    res = ft_params_to_tab(argc, argv);

    return (0);
}

