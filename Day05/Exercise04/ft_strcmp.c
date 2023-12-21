int ft_strncmp(char* s1, char* s2, unsigned int n) {
    int i;

    for (i=0; (s1[i]!='\0') && (s2[i]!='\0') && (i<n); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }

    return 0;

}

int main() {

    int first_n_bytes = 8;
    char* s1 = "string one";
    char* s2 = "string two";
    int res = ft_strncmp(s1, s2, first_n_bytes);

    return 0;
}