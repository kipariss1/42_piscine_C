#include "add_ft_opp.h"
#include "libft.h"

int ft_add(int a1, int a2){
    return a1+a2;
}

int ft_sub(int a1, int a2){
    return a1-a2;
}

int ft_mul(int a1, int a2){
    return a1*a2;
}

int ft_div(int a1, int a2){
    return a1/a2;
}

int ft_mod(int a1, int a2){
    return a1%a2;
}

int ft_usage(int a1, int a2){

    ft_putstr("error : only [ - + * / % ] are accepted ");

    return (0);
}

