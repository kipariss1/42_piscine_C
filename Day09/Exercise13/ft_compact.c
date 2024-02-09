int ft_compact(char **tab, int length){
    int n_of_null_elements = 0;
    for (int i=0; i<length; i++){
        if (tab[i]==0){
            n_of_null_elements++;
            for (int k=i; k<length-1; k++){
                tab[k] = tab[k+1];
            }
        }
    }

    for (int i=0; i<n_of_null_elements; i++){
        tab[length-1-i]='\0';
    }

    return length-n_of_null_elements;
}

int main(){
    int len = 8;
    char *tab[len];
    tab[0] = "test";
    tab[1] = 0;
    tab[2] = "test2";
    tab[3] = "test3";
    tab[4] = "test4";
    tab[5] = 0;
    tab[6] = "test5";
    tab[7] = "test6";

    int res = ft_compact(tab, len);

    return (0);
}