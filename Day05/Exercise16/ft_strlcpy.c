int ft_strlen(char *str) {
    int i;

    for (i=0; str[i]!='\0'; i++) {}

    return i;
}

unsigned int ft_strlcpy(char* dest, char* src, unsigned int size) {
    
    int i;

    int src_len = ft_strlen(src);

    for (i=0; src[i]!='\0' && i<(size-1); i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return src_len;
}

int main() {
    char first_str[] = "This is the bend";
    char second_str[] = "This is the end ";

    unsigned int res = ft_strlcpy(first_str, second_str, 4);

    return 0;
}