#include <unistd.h>

void ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
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

    unsigned int n_rows = size/0x10;


    for (int i=0; i<n_rows; i++) {

        char template[] = "00000000";
        int len_template = 8;

        convert_to_hex_str(i, template, len_template);

        for (int j=0; template[j]!='\0'; j++) {
            ft_putchar(template[j]);
        }

        ft_putchar(':');
        ft_putchar(' ');

        char *new_addr;

        // TODO: put here hex containings of the memory

        // char *new_addr = addr+0x01; recast pointer from void to char and now we're able to manipulate them
        for (new_addr = addr + 0x10*i; new_addr != addr + 0x10*i + 0x10 && *new_addr != '\0'; new_addr = new_addr + 0x01) {
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
    char text[] = "Salut les aminches c'est cool show mem on fait de truc terrible.................";

    ft_print_memory(&text, 0x50); // need to output 0x40 ~ 64 bytes, starting from text beginning
    // ft_print_memory(&text, 0);
    return 0;
}
