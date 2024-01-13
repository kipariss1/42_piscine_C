int ft_strncmp(char* s1, char* s2, unsigned int n) {
    int i;

    for (i=0; (s1[i]!='\0') && (s2[i]!='\0') && (i<n); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }

    return 0;

}
