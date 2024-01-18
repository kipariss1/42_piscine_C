#include "libft.h"

int main(int argc, char *argv[]) {

    for (int i=argc-1; i>0; i--) {
        ft_putstr(argv[i]);
        ft_putchar('\n');
    }

    return 0;
}