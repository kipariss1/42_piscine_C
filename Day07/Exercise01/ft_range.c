#include <stdlib.h>

int* ft_range(int min, int max) {
    if (min>max) {
        return NULL;
    }

    int *res = (int*)malloc((max-min)*sizeof(int));

    for (int i=1; i<(max-min); i++){
        *(res+i) = min + i;
    }

    return res;

}

int main() {
    int min = 9;
    int max = 18;

    int *res = ft_range(min, max);

    return 0;
}
