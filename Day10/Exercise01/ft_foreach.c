#include "libft.h"

void ft_foreach(char *tab, int length, void(*f)(char)){

    for (int i=0; i<length; i++){
        f(tab[i]);
    }

}

int main(){

    char tab[] = {'1', '2', '3', '4', '5'};
    int len = 5;

    ft_foreach(tab, len, &ft_putchar);

    return (0);
}