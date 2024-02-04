#include "libstr.h"

void strip_non_letters(char *str){
    int begin_idx = -1;
    int end_idx;
    int len_str;
    for (len_str=0; str[len_str]!='\0'; len_str++){
        if (is_letter(str[len_str]) && begin_idx==-1){
            begin_idx = len_str;
        }
    }
    for (end_idx=len_str; is_letter(str[end_idx])!=1; end_idx--){}

    for (int i=0; i<len_str; i++){
        if (i>(end_idx-begin_idx)){
            str[i] = '\0';
            continue;
        }
        str[i] = str[begin_idx+i];
    }
}