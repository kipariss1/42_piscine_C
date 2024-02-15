#include <stdlib.h>

int* ft_map(int *tab, int length, int(*f)(int)){
    int *res = (int*)malloc(length*sizeof(int));

    for (int i=0; i<length; i++){
        res[i] = f(tab[i]);
    }

    return res;
}

int example_func(int in){
    return in/2 + 1;
}

int main(){

    int test[] = {1, 2, 3, 4, 5};
    int len = 5;

    int *res = ft_map(test, len, &example_func);

    return (0);
}
