int is_digit(char symbol) {
    if ((symbol>47) && (symbol<58)) {
        return 1;
    }

    return 0;
}

int ft_str_is_numeric(char* str) {

    for (int i=0; str[i] != '\0'; i++) {
        if (!(is_digit(str[i]))) {
            return 0;
        } 
    }

    return 1;

}

int main() {
    char str[] = "41234123455";
    char str1[] = "123 this is not numeric stringe";

    int res = ft_str_is_numeric(str);
    int res1 = ft_str_is_numeric(str1);

    return 0;
}