#include <unistd.h>

void ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}

int ft_strlen(char *str) {
    int i;

    for (i=0; str[i]!='\0'; i++) {}

    return i;
}

void translate_to_base_system(int digit, int base, char* base_system) {
    int remainder = digit%base;

    if (digit>=base) {
        translate_to_base_system(digit/base, base, base_system);
    }

    ft_putchar(base_system[remainder]);
}

void ft_putnbr_base(int nbr, char* base) {
    // CHECKING INPUTS

    // checking if base has at least 2 characters
    int len_base = ft_strlen(base);
    if (len_base<2) {
        return;
    }

    // checking if base has the same character twice and if base contains '+' or '-'
    for (int i=0; i<(len_base-1); i++) {

        if ((base[i] == '+') || (base[i] == '-') || (base[i+1] == '+') || (base[i+1] == '-')) {
            return;
        }

        for (int j=i+1; j<(len_base); j++) {
            if (base[i] == base[j]) {
                return;
            } 
        }
    }

    // handling the negatibe "nbr"
    if (nbr<0) {
        ft_putchar('-');
        nbr = nbr*-1;
    }

    // translating "nbr" from decimal to "base" system
   translate_to_base_system(nbr, len_base, base); 

}

int main() {

    char base[] = "0123456789ABCDEF";
    ft_putnbr_base(-4220, base);

    return 0;
}
