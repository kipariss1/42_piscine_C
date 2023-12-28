int is_letter(char symbol) {
    if ((symbol>96) && (symbol<123)) {
        return 1;
    }

    return 0;
}

int ft_str_is_lowercase(char* str) {

    for (int i=0; str[i] != '\0'; i++) {
        if (!(is_letter(str[i]))) {
            return 0;
        }
    }

    return 1;

}

int main() {
    char str[] = "thisislowercasestring";
    char str1[] = "This is not lowercase string";

    int res = ft_str_is_lowercase(str);
    int res1 = ft_str_is_lowercase(str1);

    return 0;
}