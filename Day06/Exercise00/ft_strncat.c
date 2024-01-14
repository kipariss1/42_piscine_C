int ft_strlen(char *str){

	int count = 0;

	while (*(str+count) != '\0') {
		count++;
	}

	return count;

}

char* ft_strncat(char *dest, char *src, int n) {

    int len_dest = ft_strlen(dest);

    int i;

    for (i=0; src[i]!='\0' && i<n; i++) {
        dest[len_dest + i] = src[i];
    }

    dest[len_dest + i] = '\0';

    return dest;
}