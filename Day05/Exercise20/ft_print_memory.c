#include <unistd.h>

void ft_putchar(char c)
{
 // one is the file descriptor (something like pointer) and 1 is the file descriptor of file that takes care of output screen
  write(1, &c, 1);
}

void* ft_print_memory(void *addr, unsigned int size) {
    // should return addr

    if (size == 0) {
        return NULL;    // TODO: look, how to return pointer to empy pointer  
    }
}

int main() {
    char text[] = "Salut les aminch es c'est cool show mem on fait d e truc terrible.................";

    ft_print_memory(&text, 0x40); // need to output 0x40 ~ 64 bytes, starting from text beginning

    return 0;
}
