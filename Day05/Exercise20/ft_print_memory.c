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


long long int ft_pow(int base, int pow) {
    int res = 1;
    for (; pow != 0; pow--) {
        res = res*base;
    }

    return res;
}

void convert_to_hex_str(int iter_to_convert, char* res, int len_of_res) {

    int ascii_offset = 48;

    iter_to_convert = iter_to_convert*10;
    
    for (int i = len_of_res; i != 0; i--) {

        if (iter_to_convert/ft_pow(10, i) == 0) {
            continue;
        }
        else {
            res[len_of_res - i - 1] = iter_to_convert/ft_pow(10, i) + ascii_offset;
            iter_to_convert = iter_to_convert%(10^i);
        }
        
    }
}

// void* is a pointer to non-specific datatype (hence - any datatype)
void* ft_print_memory(void *addr, unsigned int size) {
    // should return addr

    if (size == 0) {
        return addr;    // returning addr as a pointer if size is 0 and nothing is displayed 
    }

    // adding one more iteration for main for cycle, if there is some remainder of bytes to display
    unsigned int n_rows = size/0x10;
    if (size%0x10 != 0) {
        n_rows++;
    }

    char base[] = "0123456789abcdef";
    char template[] = "00000000";


    for (int i=0; i<n_rows; i++) {

        int len_template = 8;

        convert_to_hex_str(i, template, len_template);

        for (int j=0; template[j]!='\0'; j++) {
            ft_putchar(template[j]);
        }

        ft_putchar(':');
        ft_putchar(' ');

        // Printing hex containment of the memory
        char *hex_new_addr;
        int itr = 0;    // iterator for putting space every two bytes
        int skip_flag = 0; // flag, indicating, that '\0' sign was reached and there is nothing to print in that row

        for (hex_new_addr = addr + 0x10*i; hex_new_addr != addr + 0x10*i + 0x10; hex_new_addr = hex_new_addr + 0x01) {
            if (*hex_new_addr == '\0' || hex_new_addr == addr + size) {
                skip_flag = 1;
            }

            if (skip_flag != 1) {
                // putting 0 before byte content because if it's < 16 -> x instead of 0x will be printed 
                if (*hex_new_addr<0x10) {
                    ft_putchar('0');
                }

                ft_putnbr_base(*hex_new_addr, base);
            }
            else {
                ft_putchar(' ');
                ft_putchar(' ');
            }


            itr++;
            if (itr%2 == 0) {
                ft_putchar(' ');
                itr = 0;
            }
        }

        ft_putchar(' ');    // putting one more space between 2nd and 3d columns

        // Printing char containing of the memory
        char *new_addr;

        // char *new_addr = addr+0x01; recast pointer from void to char and now we're able to manipulate them
        for (new_addr = addr + 0x10*i; new_addr != addr + 0x10*i + 0x10 && *new_addr != '\0' && new_addr != addr+size; new_addr = new_addr + 0x01) {
            // manipulating the casted char
            if (*new_addr>31) {
                ft_putchar(*new_addr);  // if printable - print
            }
            else {
                ft_putchar('.');    // if not printable - replace by dot
            }
        }

        ft_putchar('\n');

        if (*new_addr == '\0') {
            break;
        }
    }

    return addr;

}

int main() {
    char text[] = "Salut les aminches c'est cool show mem on fait de truc terrible................";
    int test[] = {51, 3423, 4, 24, 1234, 43, 1, 343, 4, 0, 0, 34};

    ft_print_memory(&text, 0x4a); // need to output 0x40 ~ 64 bytes, starting from text beginning
    // ft_print_memory(&text, 0);
    return 0;
}
