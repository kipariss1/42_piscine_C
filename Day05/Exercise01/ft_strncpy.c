char* ft_strcpy(char* dest, char* src, unsigned int n) {
    int i;

    for (i=0; (src[i]!='\0') && (i<n); i++) {
        dest[i] = src[i];
    }  
    for (;i<=n; i++) {
        dest[i] = '\0';
    }

    return dest; 
}

int main() {
    char src[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'y', '\0'};
    char dest[10] = {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '\0'};

    int n = 5;

    char* res = ft_strcpy(dest, src, n);

    return 0;
}