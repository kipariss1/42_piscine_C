int ft_strlen(char *str) {
    int i;

    for (i=0; str[i]!='\0'; i++) {}

    return i;
}

char* ft_strncat(char *dest, char *src, int n) {

    int len_dest = ft_strlen(dest);

    int i;

    for (i=0; src[i]!='\0' && i<n; i++) {
        dest[len_dest + i] = src[i];
    }

    dest[len_dest + i] = '\0';

    return dest;
}

int main() {

    char first_str[50] = "This is beginning "; // dest should have space for src string to fit
    char second_str[] = "and this is continuation";

    ft_strncat(first_str, second_str, 10);

    return 0;
}