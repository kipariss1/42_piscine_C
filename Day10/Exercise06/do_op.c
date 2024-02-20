#include "libft.h"

int is_valid_operand(char *test_str){
    char valid_operands[] = "+-/%";

    // if operand has more than one symbol, it's invalid
    for (int i=0; test_str[i]!='\0'; i++){
        if (i>0){
            return 0;
        }
    }

    for (int i=0; valid_operands[i]!='\0';i++){
        if (test_str[0]==valid_operands[i]){
            return 1;
        }
    }

    return 0;
}

void parse_arg(char *arg){
    int is_negative = 0;
    if (arg[0]=='-'){
        is_negative = 1;
    }

    int i=0;
    if (is_negative){
        i = 1;
    }
    int to_zero_out_flag = 0;
    for (; arg[i]!='\0'; i++){
        if (!(arg[i]>47 && arg[i]<58)){
            to_zero_out_flag = 1;
        }
        if (to_zero_out_flag){
            arg[i] = '\0';
        }
    }
}

int do_calculation(int ac, char *av[]){

    char *first_arg = av[1];
    char *operand = av[2];
    char *second_arg = av[3];

    if (!is_valid_operand(operand)){
        return 0;
    }

    // leaves only first digits in args
    parse_arg(first_arg);
    parse_arg(second_arg);

    int first_arg_int = ft_str_to_int(first_arg);
    int second_arg_int = ft_str_to_int(second_arg);

    if (operand[0]=='+'){
        return first_arg_int + second_arg_int;
    }
    else if (operand[0]=='-') {
        return first_arg_int - second_arg_int;
    }
    else if (operand[0]=='/') {
        return first_arg_int / second_arg_int;
    }
    else if (operand[0]=='%') {
        return first_arg_int % second_arg_int;
    }
}

int main(int argc, char *argv[]){
    // check the input args
    parse_arg(argv[3]);
    if (!ft_strcmp(argv[3], "0") && (argv[2][0]=='/')){
        ft_putstr("Stop : division by zero");
        ft_putchar('\n');
        return 0;
    }

    parse_arg(argv[3]);
    if (!ft_strcmp(argv[3], "0") && (argv[2][0]=='%')){
        ft_putstr("Stop : modulo by zero");
        ft_putchar('\n');
        return 0;
    }

    // do main calculation
    int res_is_negative = 0;
    int res = do_calculation(argc, argv);
    if (res==0){
        ft_putstr("0");
        ft_putchar('\n');
        return (0);
    }
    if (res<0){
        res_is_negative = 1;
        res = res * -1;
    }

    // do the res conversion from int to str

    int len_res = 0;
    int res_copy = res;
    while (res_copy!=0){
        res_copy = res_copy/10;
        len_res++;
    }

    char str_res[len_res];
    ft_initstr(str_res, len_res);

    ft_int_to_str(str_res, res, len_res);
    if (res_is_negative){
        ft_putchar('-');
    }
    ft_putstr(str_res);
    ft_putchar('\n');

    return (0);
}