int is_letter(char ch){
    if ((l_big < ch && ch < h_big) || (l_small < ch && ch < h_small)){
        return 1;
    }

    return 0;
}