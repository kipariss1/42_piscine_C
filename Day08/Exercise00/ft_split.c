#include <stdlib.h>

int is_separator(char ch, char *charset){

    for (int i=0; charset[i]!='\0'; i++){
        if (ch==charset[i]){
            return 1;
        }
    }

    return 0;
}

char** ft_split_whitespaces(char *str, char *charset){     

    int n_words = 0;
    for (int i=0; str[i]!='\0'; i++){
        if (is_separator(str[i], charset)){
            n_words++;
        }
    } 
    n_words++;

    int words_len[n_words];
    int curr_word = 0;
    int curr_word_len = 0;

    for (int i=0; str[i]!='\0'; i++){
        if (!is_separator(str[i], charset)){
            curr_word_len++;
        }
        else if ((is_separator(str[i], charset)) && (curr_word_len==0)){
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

        if (!is_separator(str[i], charset)){
            res[curr_word][curr_word_i] = str[i];
            curr_word_i++;
        }
        else if ((is_separator(str[i], charset)) && (curr_word_i==0)){
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

char** ft_split(char *str, char *charset){
    return ft_split_whitespaces(str, charset);
}
/*
int main(){

    char test[] = "This is Test string, whIch will be spliTted";
    char charset[] = "TI";

    char **res = ft_split(test, charset);

    return 0;
}
*/
