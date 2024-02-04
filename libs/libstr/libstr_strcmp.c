#include "libstr.h"

int strcmp(char *str1, char *str2){

    int i;

    for (i=0; str1[i]!='\0' && str2[i]!='\0'; i++){
        if (str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
    } 

    return str1[i] - str2[i]; 
}