#include <stdlib.h>
#include "libft.h"

char* ft_convert_base(char *nbr, char *base_from, char *base_to){

    // check if nbr is in the base
    int is_in_base_flag = 1;
    for (int i=0; nbr[i] != '\0'; i++){
        int j;
        for (j=0; base_from[j] != '\0'; j++){
            if (nbr[i] == base_from[j]){
                break;
            }
        } 

        if (j==ft_strlen(base_from)){
            return NULL;        // if there is no such symbol in base_from --> error --> return null pointer
        }
    }    

    int orig_base_len = ft_strlen(base_from);  
    int dest_base_len = ft_strlen(base_to);
 
    // TODO: finish
    return (char*)malloc(1*sizeof(char));
}

int main() {

    char nbr[] ="16";
    char base_from[] = "0123456789";
    char base_to[] = "0123456789ABCDEF";

    char *res = ft_convert_base(nbr, base_from, base_to);

    return 0;
}
