#include <unistd.h>

void ft_generic(void){
    char string[] = "Tu tu tu tu ; Tu tu tu tu \n";
    int len_str;
    for (len_str=0; string[len_str] != '\0'; len_str++){}
    int size_char_in_bytes = 1;
    int fd = 1; // file descriptor

    write(fd, string, len_str*size_char_in_bytes);
}

int main(){
    ft_generic();
    return (0);
}



