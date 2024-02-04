#include "libstr.h"

void to_lowercase(char *str){
    for (int i=0; str[i]!='\0'; i++){
        if (is_uppercase(str[i])){
            str[i] = str[i] + OFFSET;
        }
    }
}