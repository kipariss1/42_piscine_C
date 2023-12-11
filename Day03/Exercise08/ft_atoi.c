int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}


int my_pow(int digit, int degree) {

	if (degree == 0) {
		return 1;
	}

	long long int outP = digit;

	while (degree != 1) {
		outP = outP*digit;
		degree -= 1;
	}

	return outP;
}


int ft_atoi(char *str) {

	int res = 0;
	int ascii_offset = 48;

	int len = ft_strlen(str);
	for (int i=0; i<len; i++) {
		res = res + (*(str+i) - ascii_offset)*my_pow(10, len - 1 - i); 
	}		

	return res;	

}


void main(){

	char str[20] = "9873";
	int str2int = ft_atoi(str);

}
