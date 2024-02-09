#include "ft_perso.h"
#include <stdlib.h>
#include "libft.h"

char** split_string(char *str, char delimeter){
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

int str_to_int(char *str){

    int len_str;
    for (len_str=1; str[len_str]!='\0'; len_str++){}

    int ascii_offset = 48;
    int res = 0;

    for (int i=0; str[i]!='\0'; i++){
        int digit  = str[i] - ascii_offset;
        res = res + digit*ft_iterative_power(10, len_str-1-i);
    }

    return res;
}

t_perso** ft_decrypt(char *str){
    char **persons = split_string(str, ';');

    int len_persons;
    for (len_persons=0; persons[len_persons]!=0; len_persons++){}

    t_perso **res = (t_perso**)malloc(len_persons*sizeof(t_perso*));

    for (int i=0; i<len_persons; i++){
        char **person_with_age_and_name = split_string(persons[i], '|');
        char *str_age = person_with_age_and_name[0];
        char *name = person_with_age_and_name[1];
        int age = str_to_int(str_age);
        res[i] = (t_perso*)malloc(sizeof(t_perso));
        res[i]->age = age;
        res[i]->name = name;
    } 

    return res;
}

int main(int argc, char argv[]){
    // TODO: make it decrypt from arguments
    char str[] = "14|Greta;22|Sasha;45|Pamella";

    t_perso **res = ft_decrypt(str);

    return (0);
}
