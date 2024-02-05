void ft_scrambler(int ***a, int *b, int *******c, int ****d){
    
    int temp1 = ***a;
    ***a = *b;
    int temp2 = *******c;
    *******c = temp1;
    temp1 = ****d;
    ****d = temp2;
    *b = temp2;

}

int main(){

    int a = 5;
    int *p_a = &a;
    int **pp_a = &p_a;
    int ***ppp_a = &pp_a;

    int b = 10;
    int *p_b = &b;

    int c = 15;
    int *p_c = &c;
    int **pp_c = &p_c;
    int ***ppp_c = &pp_c;
    int ****pppp_c = &ppp_c;
    int *****ppppp_c = &pppp_c;
    int ******pppppp_c = &ppppp_c;
    int *******ppppppp_c = &pppppp_c;

    int d = 20;
    int *p_d = &d;
    int **pp_d = &p_d;
    int ***ppp_d = &pp_d;
    int ****pppp_d = &ppp_d;

    ft_scrambler(ppp_a, p_b, ppppppp_c, pppp_d);

    return (0);
}