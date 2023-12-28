int is_capital_letter(char symbol) {
    if ((symbol>64) && (symbol<91)) {
        return 1;
    }

    return 0;
}

int is_letter(char symbol) {
    if ((symbol>96) && (symbol<123)) {
        return 1;
    }

    return 0;
}

int ft_str_is_alpha(char* str) {

    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (!(is_letter(str[i])) && !(is_capital_letter(str[i]))) {
            return 0;
        }
    }    

    return 1;

}

int main() {
    char str[] = "thisisalphanumerIcstring";
    char str1[] = "this is not alphanumeric string";

    int res = ft_str_is_alpha(str);
    int res1 = ft_str_is_alpha(str1);

    return 0;
}