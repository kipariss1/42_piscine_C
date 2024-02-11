int remove_element(int *tab, int n_element_to_remove, int length){
    for (int i=n_element_to_remove; i<length-1; i++){
        tab[i] = tab[i+1]; 
    } 

    tab[length-1] = 0;

    // returns new length of tab
    return length-1;
}

int ft_unmatch(int *tab, int length){

    // if only one element was left in array -> return this element
    if (length==1){
        return tab[0];
    }

    int first_element_has_pair = 0;
    for (int i=1; i<length; i++){
        if (tab[i] == tab[0]){
            first_element_has_pair = 1;
            int new_len = remove_element(tab, 0, remove_element(tab, i, length));
            ft_unmatch(tab, new_len);
            break;
        }
    }

    // if duplicate is found in for cyclus, the rest is recursively anihilated and only left without duplicate is 0-th element, if not - it's 0-th element
    return tab[0];
}

int main(){

    int array[] = {1, 1, 2, 3, 4, 3, 4};

    int res = ft_unmatch(array, 9);

    return (0);
}
