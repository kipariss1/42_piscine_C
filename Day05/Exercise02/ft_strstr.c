int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;
}

char* ft_strstr(char *str, char *to_find) {
    int len_str = ft_strlen(str);
    int len_to_find = ft_strlen(to_find);

    if (len_to_find>=len_str) {
        return 0;
    }

    int isFound;

    for (int i = 0; i<len_str - len_to_find; i++) {

        isFound = 1;

        for (int j = 0; j<len_to_find; j++) {
            if (to_find[j] != str[i+j]) {
                isFound = 0;
                break;
            }
        }

        if (isFound == 1) {
            return str+i;
        }
    }

    return 0;
}

int main() {
    char str[16] = {'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', ' ', 'w', 'o', 'r', 'l' ,'d', '!', '\0'};
    char to_find[6] = {'w', 'o', 'r', 'l', 'd', '\0'};

    char* res = ft_strstr(str, to_find);

    return 0;
}