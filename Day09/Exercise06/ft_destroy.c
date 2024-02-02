#include <stdlib.h>

// This one needs to be tested in the piscine itself
void ft_destroy(char ***factory){
    free(**factory);
}
