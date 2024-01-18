#include <stdlib.h>

char* ft_strdup(char *src){

    int len;
    for (len=0; src[len] != '\0'; len++){}

    char *dup = (char*)malloc(sizeof(char)*(len+1));

    int i;
    for (i=0; src[i] != '\0'; i++) {
        *(dup+i) = src[i];
    }

    *(dup+i) = '\0';

    return dup;

}

int main() {

    char test[] = "this is test";

    char *dup = ft_strdup(test);

    return 0;
}
