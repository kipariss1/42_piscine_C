#include "libstr.h"

char** std_split_string(char *str, char delimeter){
    // counting how many parts it will be splitted to
    int n_of_substrings = 1;
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]==delimeter){
            n_of_substrings++;
        }
    }

    // if no additional substrings found return array, return null 
    if (n_of_substrings==1){
        return 0;
    }

    // allocating space for substrings (n_of_substrings+1) for adding terminating null element
    char **splitted_string = (char**)malloc((n_of_substrings+1)*sizeof(char*)); 

    // splitting string
    int begin = 0;
    int end = 0;
    int n_of_substring = 0;
    int str_len = 0;

    for (int i=0; str[i]!='\0';i++){
        if (str[i]==delimeter){
            if (!begin && !end){
                end = i;
            }
            else {
                begin = end + 1;
                end = i;
            }

            splitted_string[n_of_substring] = (char*)malloc((end-begin)*sizeof(char));

            for (int j=0; j<(end-begin); j++){
                splitted_string[n_of_substring][j] = str[begin+j];
            }

            n_of_substring++;
        }
        str_len++;
    }

    // adding the leftovers from for cycle 
    begin = end + 1;
    end = str_len;
    splitted_string[n_of_substring] = (char*)malloc((end-begin)*sizeof(char));
   for (int j=0; j<(end-begin); j++){
        splitted_string[n_of_substring][j] = str[begin+j];
    }

    // adding terminating null element
    n_of_substring++;
    splitted_string[n_of_substring] = 0;

    return splitted_string;
}
