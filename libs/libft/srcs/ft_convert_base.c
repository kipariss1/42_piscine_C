#include <stdlib.h>
#include "libft.h"

int find_char_in_str(char ch, char *str){
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]==ch){
            return i;
        }
    }

    return -1;
}

void translate_to_base_system(int digit, int base, char* base_system, char* dest) {
    int remainder = digit%base;

    if (digit>=base) {
        translate_to_base_system(digit/base, base, base_system, dest);
    }

    char *base_digit = (char*)malloc(1*sizeof(char));
    *base_digit = base_system[remainder]; 
    ft_strcat(dest, base_digit);
}

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
    long long int decimal_num = 0;

    for (int i=0; i<ft_strlen(nbr); i++){ 
        decimal_num = decimal_num + find_char_in_str(nbr[i], base_from)*ft_iterative_power(orig_base_len, ft_strlen(nbr) - i - 1);   
    }

    // Convert to dest base system
    int base_to_n_of_digits;
    long long int converted_num_copy = decimal_num;

    for (base_to_n_of_digits=0; converted_num_copy>0; base_to_n_of_digits++){
        converted_num_copy = converted_num_copy/dest_base_len;
    }

    char *converted_num = (char*)malloc(base_to_n_of_digits*sizeof(char));
    ft_initstr(converted_num, base_to_n_of_digits);

    translate_to_base_system(decimal_num, dest_base_len, base_to, converted_num);

    (void)is_in_base_flag;
 
    return converted_num;
}

// int main() {

//     char nbr[] ="16";
//     char base_from[] = "0123456789";
//     char base_to[] = "0123456789ABCDEF";

//     char *res = ft_convert_base(nbr, base_from, base_to);

//     return 0;
// }
