#include "ft_boolean.h"
#include <stdio.h>

int main(){

    t_bool test = FALSE;

    if (test == FALSE){
        printf("FALSE and TRUE defs are working \n");
    }

    ft_putstr("This is test string \n");

    EVEN(2) == TRUE ? printf("EVEN() function declaration is working \n") : printf("EVEN() function is still working but wrongly \n");

    return 0;
}
