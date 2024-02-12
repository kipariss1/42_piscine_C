#include "libft.h"

int ft_strcmp(char *s1, char *s2) {

    int i;

    for (i=0; (s1[i]!='\0') && (s2[i]!='\0'); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        } 
    }

    if ((s1[i]=='\0') || (s2[i]=='\0')) {
        return s1[i] - s2[i];
    }

    return 0;

}

/*
int main() {
    char* s1 = "string";
    char* s2 = "string two";

    int res = ft_strcmp(s1, s2);

    return 0;
}
*/