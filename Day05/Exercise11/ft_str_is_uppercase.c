int is_capital_letter(char symbol) {
    if ((symbol>64) && (symbol<91)) {
        return 1;
    }

    return 0;
}

int ft_str_is_uppercase(char* str) {

    for (int i=0; str[i] != '\0'; i++) {
        if (!(is_capital_letter(str[i]))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    
    char str[] = "THISISUPPERCASESTRING";   
    char str1[] = "THIS is not uppercase string";

    int res = ft_str_is_uppercase(str);
    int res1 = ft_str_is_uppercase(str1);

    return 0;
}