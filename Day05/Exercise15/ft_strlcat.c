int ft_strlen(char *str) {
    int i;

    for (i=0; str[i]!='\0'; i++) {}

    return i;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size) {
    // size is size (not len, len is used part, size is allocated size) of dest
    int dest_filled_part_len = ft_strlen(dest);

    int i;

    for (i=0; src[i]!='\0' && (dest_filled_part_len+i)<size-1; i++) {
        dest[dest_filled_part_len+i] = src[i];
    }

    // strlcat is guaranteed to end dest with \0
    dest[i] = '\0'; 

    return i;
}

int main() {

    const unsigned int first_str_size = 50;

    char first_str[50] = "This is beginning "; // dest should have space for src string to fit
    char second_str[] = "and this is continuation blah blah blah blah";

    unsigned int concateneted_len = ft_strlcat(first_str, second_str, first_str_size); // returns appended len to check if all of the second str was appended

    return 0;
}
