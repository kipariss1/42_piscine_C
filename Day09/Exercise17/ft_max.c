int ft_max(int *tab, int length){

    // do bubble sort and return last member

    for (int j=0; j<length-1;j++){
        if (tab[j]>tab[j+1]){
            int temp = tab[j+1];
            tab[j+1] = tab[j];
            tab[j] = temp;
        }
    }

    return tab[length-1];

}

int main(){

    int tab[] = {25, 0, 111, 54, 4, 110, 34};

    int res = ft_max(tab, 7);

    return (0);
}
