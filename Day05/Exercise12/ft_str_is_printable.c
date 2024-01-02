int ft_str_is_printable(char* str) {
    


    for (int i=0; str[i] != '\0'; i++) {

        if (str[i]<32) {
            return 0;
        }

    }

    return 1;
}

int main() {

    char str[] = "This is fully printable string";
    char str1[] = "\x01\x05\x15\x0a";

    int res = ft_str_is_printable(str);
    int res1 = ft_str_is_printable(str1);

    return 0;
}
