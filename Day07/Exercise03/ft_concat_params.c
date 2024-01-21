#include <stdlib.h>
#include "libft.h"

char* ft_concat_params(int argc, char **argv){
    
    int len_argv = 0;
    for (int i=0; i<argc; i++) {
        len_argv = len_argv + ft_strlen(argv[i]) + 1;       // 1 is for "\n" symbol
    }

    char* res = (char*)malloc(len_argv*sizeof(char));

    for (int i=0; i<argc; i++){
        ft_strcat(res, argv[i]);
        ft_strcat(res, "\n");       // if we straight pass "some string", it will be passed as pointer to "some string"
    }

    return res;

}

int main(int argc, char* argv[]){       // we've given the array of pointers

    char *res = ft_concat_params(argc, argv);   // and arrays are passed by reference always, so that leaves as with pointer to pointer
                                                // (first element of array) as a function argument
    ft_putstr(res);

    return 0;
}
