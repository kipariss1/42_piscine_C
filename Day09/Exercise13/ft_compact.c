int ft_compact(char **tab, int length){
    // TODO: somehow bubble up nulls to the end

    int n_of_null_elements = 0;
    for (int i=0; i<length; i++){
        if (tab[i]==0){
            n_of_null_elements++;
            for (int k=i; k<length-1; k++){
                tab[k] = tab[k+1];
            }
        }
    }

    return length-n_of_null_elements;
}

int main(){

    char *tab[5];
    tab[0] = "test";
    tab[1] = 0;
    tab[2] = "test2";
    tab[3] = "test3";
    tab[4] = "test4";

    int res = ft_compact(tab, 5);

    return (0);
}