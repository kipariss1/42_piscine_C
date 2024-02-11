#include "libstr.h"

char* std_join(char **tab, char *sep){

    unsigned int res_len = 0;
    int tab_len;
    for (tab_len=0; tab[tab_len]!=0; tab_len++){}

    int i;
    for (i=0; i<tab_len-1; i++){
        res_len = res_len + my_strlen(tab[i]);
        res_len = res_len + my_strlen(sep);
    }
    res_len = res_len + my_strlen(tab[i]);

    char *res = (char*)malloc(++res_len*sizeof(char));

    for (i=0; i<tab_len-1; i++){
        my_strlcat(res, tab[i], res_len);
        my_strlcat(res, sep, res_len);
    }  
    my_strlcat(res, tab[i], res_len);

    return res;
}
