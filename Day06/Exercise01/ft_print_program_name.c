#include "libft.h"

int main(int argc, char *argv[]) {
    int temp_len = ft_strlen(argv[0]);
    char temp[temp_len];
    ft_initstr(temp, temp_len);   // init array

    ft_strcpy(temp, argv[0]); 

    for (int i=0; temp[i] != '\0'; i++) {

       ft_putchar(temp[i]);

    }

    ft_putchar('\n');
    
    return 0;
}
