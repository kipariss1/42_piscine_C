#include "ft_sort_wordtab_advanced.h"
#include "libft.h"

void ft_sort_wordtab_advanced(char **tab, int(*cmp)(char*, char*)){

    int len_tab;
    for (len_tab=0; tab[len_tab]!=0; len_tab++){}

    for (int i=0; i<len_tab; i++){
        for (int j=0; j<len_tab-1-i; j++){
            if (cmp(tab[j], tab[j+1])>0){
                char *temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp; 
            }
        } 
    }

}

int main(int argc, char *argv[]){

    char **tab = ft_split_whitespaces(argv[1]);

    ft_sort_wordtab_advanced(tab, &ft_strcmp); 

    for (int i=0; tab[i]!=0; i++){
        ft_putstr(tab[i]);
        ft_putstr(", ");
    }

    ft_putchar('\n');

    return (0);
}