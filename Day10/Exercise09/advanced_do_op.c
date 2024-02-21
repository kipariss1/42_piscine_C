#include "libft.h"
#include "ft_opp.h"

// check validity and format if operator is not valid
int is_valid_operand(char *test_str){
    char valid_operands[] = "+-*/%";

    int is_valid_flag = 1;
    unsigned int len_test_str = 0;

    // if operand has more than one symbol, it's invalid
    for (int i=0; test_str[i]!='\0'; i++){
        if (i>0){
            is_valid_flag = 0;
        }
        len_test_str++;
    }
    
    if (is_valid_flag){
        for (int i=0; valid_operands[i]!='\0'; i++){
            if (test_str[0]==valid_operands[i]){
                return 1;
            }
        }
    }

    ft_initstr(test_str, len_test_str);         // formatting the string

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

t_opp* get_operation_by_operator(char *operator){
    int i;
    for (i=0; g_opptab[i].ft_operator[0]!='\0'; i++){
        if (ft_strcmp(operator, g_opptab[i].ft_operator)==0){
            return &g_opptab[i];
        }
    }
    if (ft_strcmp(operator, g_opptab[i].ft_operator)==0){
        return &g_opptab[i];
    }

    return 0;    
}

int do_calculation(char *first_arg, char *second_arg, int(*f)(int,int)){

    // leaves only first digits in args
    parse_arg(first_arg);
    parse_arg(second_arg);

    int first_arg_int = ft_str_to_int(first_arg);
    int second_arg_int = ft_str_to_int(second_arg);

    return f(first_arg_int, second_arg_int);
}

int main(int argc, char *argv[]){
    // check the input args (arguments, operator)
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

    is_valid_operand(argv[2]);

    int res_is_negative = 0;

    // do main calculation
    // "get_operation_by_operator" returns pointer to function by symbol
    int res = do_calculation(argv[1], argv[3], get_operation_by_operator(argv[2])->operation);
    if ((res==0) && (ft_strcmp(argv[2], ""))){
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