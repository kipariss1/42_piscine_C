#include "libft.h"

void bubble_sort_arguments(int argc, char *argv[]) {
    for (int i = 1; i<argc; i++) {
        for (int j = 1; j<argc-i; j++) {
            // checking minimal len to check in both strings
            int min_len;
            if (ft_strlen(argv[j])<ft_strlen(argv[j+1])){
                min_len = ft_strlen(argv[j]);
            }
            else {
                min_len = ft_strlen(argv[j+1]);
            }
            // comparing strings
            int res = ft_strncmp(argv[j], argv[j+1], min_len);
            // swapping if needed
            if (res>0) {
                char *temp = argv[j+1];
                argv[j+1] = argv[j];
                argv[j] = temp;
            }

        }
    }
}

int main(int argc, char *argv[]) {

    bubble_sort_arguments(argc, argv);

    for (int i=1; i<argc; i++) {
        ft_putstr(argv[i]);
        ft_putchar('\n');
    }

    return 0;
}
