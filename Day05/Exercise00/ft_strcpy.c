char* ft_strcpy(char *dest, char *src) {

    int i;

    for (i=0; src[i]!='\0'; i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';

   return dest; 
}

int main() {

    char src[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', '\0'};
    char dest[10] = {'\0'};

    ft_strcpy(dest, src);

    return 0;
}