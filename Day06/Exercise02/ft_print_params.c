#include "libft.h"

int main(int argc, char *argv[]) {

    for (int i=0; i<argc; i++) {
        ft_putstr(argv[i]);
        ft_putchar('\n');
    }

    return 0;
}
