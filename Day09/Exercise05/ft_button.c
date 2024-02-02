int ft_button(int i, int j, int k){
    if ((i>=j && i<=k) || (i>=k && i<=j)){
        return i;
    }
    else if ((j>=i && j<=k) || (j>=k && j<=i)){
        return j;
    }
    else{
        return k;
    }    
}

int main(){

    int res = ft_button(1, 4, 2);

    return 0;
}