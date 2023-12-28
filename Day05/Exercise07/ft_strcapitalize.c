int is_letter(char symbol) {
    if ((symbol>96) && (symbol<123)) {
        return 1;
    }

    return 0;
}

int is_capital_letter(char symbol) {
    if ((symbol>64) && (symbol<91)) {
        return 1;
    }

    return 0;
}

int is_digit(char symbol) {
    if ((symbol>47) && (symbol<58)) {
        return 1;
    }

    return 0;
}

char* ft_strcapitalize(char* str) {

    int needToBeCapitalized = 1;
    
    for (int i=0; str[i] != '\0'; i++) {

        if (is_capital_letter(str[i]) && (needToBeCapitalized == 0)) {
            str[i] = str[i] + 32;   // decapitalize the letter
        }

        if (is_letter(str[i]) && (needToBeCapitalized == 1)) {
            str[i] = str[i] - 32;   // capitalize the letter
            needToBeCapitalized = 0;
        }

        if (is_capital_letter(str[i]) && (needToBeCapitalized == 1)) {
            needToBeCapitalized = 0;
        } 
        
        if (!(is_capital_letter(str[i]) || is_letter(str[i])) && (needToBeCapitalized==0)) {
            needToBeCapitalized = 1;
        }

        if (is_digit(str[i])) {
            needToBeCapitalized = 0;
        }
         
    } 

    return str;

}

int main() {
    char str[] = "salut, comment tu vas ? 42mots quaRante-deux; cinquante+et+un";

    char* res = ft_strcapitalize(str);

    return 0;
}