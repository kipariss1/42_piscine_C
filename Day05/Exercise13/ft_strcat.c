int ft_strlen(char *str) {
    int i;

    for (i=0; str[i]!='\0'; i++) {}

    return i;
}

char* ft_strcat(char *dest, char *src) {
    int size_of_dest = ft_strlen(dest);

    int i;

    for (i=0; src[i] != '\0'; i++) {
        dest[size_of_dest+i] = src[i];
    }
    dest[size_of_dest+i] = '\0';

    return dest;
}

int main() {

    char first_str[50] = "This is beginning "; // dest should have space for src string to fit
    char second_str[] = "and this is continuation";

    ft_strcat(first_str, second_str);

    return 0;
}