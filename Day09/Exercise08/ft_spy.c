#include <unistd.h>

// TODO: add all those functions to lib

const int l_big = 64;
const int h_big = 91;
const int l_small = 96;
const int h_small = 123;
const int offset = l_small - l_big;


void write_allert(){
    char *allert = "Allert!\n";
    int len_allert = 8;

    write(1, allert, len_allert);
}

int is_letter(char ch){
    if ((l_big < ch && ch < h_big) || (l_small < ch && ch < h_small)){
        return 1;
    }

    return 0;
}

int is_uppercase(char ch){
    if (l_big < ch && ch < h_big){
        return 1;
    }

    return 0;
}

char* to_lowercase(char *str){
    for (int i=0; str[i]!='\0'; i++){
        if (is_letter(str[i]) && is_uppercase(str[i])){
            str[i] = str[i] + offset;
        }
    }

    return str;
}

char* strip_non_letters(char *str){
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

    return str;
}

int strcmp(char *str1, char *str2){

    int i;

    for (i=0; str1[i]!='\0' && str2[i]!='\0'; i++){
        if (str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
    } 

    return str1[i] - str2[i]; 
}

void ft_spy(int ac, char **av){

    char *president = "president";
    char *attack = "attack";
    char *powers = "powers";

    for (int i=1; i<ac; i++){
        to_lowercase(av[i]);
        strip_non_letters(av[i]);
        if (strcmp(av[i], president) == 0 || strcmp(av[i], attack) == 0 || strcmp(av[i], powers) == 0){
            write_allert();
            break;
        }
    }
}

int main(int argc, char **argv){

    ft_spy(argc, argv);

    return (0);
}