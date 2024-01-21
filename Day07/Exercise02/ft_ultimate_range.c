#include <stdlib.h>

// This function, differs from previous with opportunity to take poiter to pointer to array as argument, this allows dynamical allocation
int ft_ultimate_range(int **range, int min, int max) {

    if (min>max) {
        *range = NULL;
        return 0;
    }

    *range = (int*)malloc((max-min)*sizeof(int)); 

    int i;

    for (i=0; i<(max-min); i++){
        *(*range+i) = min + i;
    }

    return i;

}

int main() {

    int min = -13;
    int max = 0;

    int *range;

    int len_range = ft_ultimate_range(&range, min, max); 

    return 0;
}
