#include <stdlib.h>
#include "ft_sort_wordtab_advanced.h"

// we're returning pointer to pointer, because we're returning pointer to array of strings
// string (array of chars) is passed around as pointer to first element and
// array of strings (array of array of chars) is passed around as pointer to first string, which is ponter to first char
// e.g. array of strings is pointer to pointer to char

int is_separator(char ch){

    if ((ch==' ') || (ch=='\t') || (ch=='\n')){
        return 1;
    }

    return 0;
}

char** ft_split_whitespaces(char *str){     

    int n_words = 0;
    for (int i=0; str[i]!='\0'; i++){
        if (is_separator(str[i])){
            n_words++;
        }
    } 
    n_words++;

    int words_len[n_words];
    int curr_word = 0;
    int curr_word_len = 0;

    for (int i=0; str[i]!='\0'; i++){
        if (!is_separator(str[i])){
            curr_word_len++;
        }
        else if ((is_separator(str[i])) && (curr_word_len==0)){
            n_words--;
            continue;
        }
        else{
            words_len[curr_word] = curr_word_len;
            curr_word++;
            curr_word_len = 0;
        } 
    }

    words_len[curr_word] = curr_word_len;

    char **res = (char**)malloc((n_words+1)*sizeof(char*));

    curr_word = 0;
    int curr_word_i = 0;
    int new_string_should_be_allocated_flag = 1;
    for (int i=0; str[i]!='\0'; i++){
        if (new_string_should_be_allocated_flag){
            res[curr_word] = (char*)malloc((words_len[curr_word]+1)*sizeof(char));
            new_string_should_be_allocated_flag = 0;
        }

        if (!is_separator(str[i])){
            res[curr_word][curr_word_i] = str[i];
            curr_word_i++;
        }
        else if ((is_separator(str[i])) && (curr_word_i==0)){
            continue;
        }
        else {
            res[curr_word][curr_word_i] = '\0';     // terminating the string 
            curr_word++;
            curr_word_i = 0;
            new_string_should_be_allocated_flag = 1;
        }

    }

    res[n_words+1] = NULL;

    return res;
}

/*
int main(){

    char str[] = "This string is need to be \t \n splitted \tthis too \nand this also blah blah blah";

    char **res = ft_split_whitespaces(str);

    return 0;
}
*/
