char rot42(char ch){

    int l_big = 64;
    int h_big = 91;
    int l_small = 96;
    int h_small = 123;

    int isSmall = 0;
    int isBig = 0;

    if (l_big < ch && ch < h_big){
        isBig = 1;
    }
    else if (l_small < ch && ch < h_small) {
        isSmall = 1;
    }
    else {
        return ch;
    }

    int remainder = ch+42;
    if (isBig){
        remainder = remainder - l_big; 
    }
    else{
        remainder = remainder - l_small;
    }
    int new_char;

    while (remainder > 0){

        if (isBig){
            new_char = l_big + remainder;
            remainder = new_char - h_big;  
        }
        else {
            new_char = l_small + remainder;
            remainder = new_char - h_small;
        }
    }

    return new_char;
}

char* ft_rot42(char *str){

    for (int i=0; str[i]!=0; i++){
        str[i] = rot42(str[i]);
    }

    return str;    

}

int main(){

    char str[] = "this is test string";
    char *res = ft_rot42(str);

    return (0);
}
