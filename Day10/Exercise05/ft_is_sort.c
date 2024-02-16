int ft_is_sort(int *tab, int length, int(*f)(int,int)){
    for (int i=0; i<length-1; i++){
        if (compare(tab[i+1], tab[i])<0){
            return 0;
        }
    }

    return 1;
}

int compare(int a1, int a2){
    if (a1==a2){
        return (0);
    }
    return a1 > a2 ? 1 : -1;
}

int main(){

    int test[] = {1, 6, 3, 4, 2, 5, 7, 8};

    int res = ft_is_sort(test, 8, &compare);

    return (0);
}