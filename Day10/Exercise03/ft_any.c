int ft_any(char **tab, int(*f)(char*)){
    for (int i=0; tab[i]!=0; i++){
        if (f(tab[i])){
            return 1;
        }
    }

    return 0;
}

int contains_w(char *test_str){
    for (int i=0; test_str[i]!='\0'; i++){
        if (test_str[i]=='w'){
            return 1;
        }
    }
    return 0;
}

int main(){

    char *tab[] = {"one", "tvo", "three", 0};
    int res = ft_any(tab, &contains_w);

    return (0);
}