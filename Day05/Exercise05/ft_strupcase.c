int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}

char* ft_strupcase(char* str) {

    int i;

    for (i=0; str[i] != '\0'; i++) {
        if ((str[i]>60) && (str[i]<123)) {
            str[i] = str[i] - 32;
        }
    }


    return str; 
}

int main() {
    char str[] = "string to be uppercase";  // char str[] - is a mutable instance of array of chars,  char* str - is pointer to the unmutable instance of array of chars
    char* res = ft_strupcase(str);

    return 0;
}