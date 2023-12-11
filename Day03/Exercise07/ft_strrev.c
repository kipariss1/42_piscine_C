int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}

char* ft_strrev(char *str) {
	int len = ft_strlen(str);
	char temp;

	for (int i=0; i<len/2; i++){
		temp = *(str+i);
		*(str+i) = *(str+len-1-i);
		*(str+len-1-i) = temp;
	}

	return str;

}

void main(){

	char str[] = "poselnahuy";
	char *new_str = ft_strrev(str);

}
