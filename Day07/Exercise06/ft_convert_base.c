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

    // checking if base_from has identical chars or contains "+" or "-"
    for (int i=0; i<(orig_base_len-1); i++) {

        if ((base_from[i] == '+') || (base_from[i] == '-') || (base_from[i+1] == '+') || (base_from[i+1] == '-')) {
            return NULL;
        }

        for (int j=i+1; j<(orig_base_len); j++) {
            if (base_from[i] == base_from[j]) {
                return NULL;
            } 
        }
    }

    // checking if base_to has identical chars or contains "+" or "-"
    for (int i=0; i<(dest_base_len-1); i++) {

        if ((base_to[i] == '+') || (base_to[i] == '-') || (base_to[i+1] == '+') || (base_to[i+1] == '-')) {
            return NULL;
        }

        for (int j=i+1; j<(dest_base_len); j++) {
            if (base_to[i] == base_to[j]) {
                return NULL;
            } 
        }
    }

    // if bases are identical, simply return the orig str
    if (!ft_strcmp(base_from, base_to)){
        return nbr;
    }

    // Convert to decimal base
    long long int converted_num = 0;

    for (int i=0; i<ft_strlen(nbr); i++){ 
        // TODO: finish
    }


 
    return (char*)malloc(1*sizeof(char));
}

int main() {

    char nbr[] ="16";
    char base_from[] = "0123456789";
    char base_to[] = "0123456789ABCDEF";

    char *res = ft_convert_base(nbr, base_from, base_to);

    return 0;
}
