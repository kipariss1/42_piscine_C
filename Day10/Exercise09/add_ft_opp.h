#ifndef __ADDITIONAL_FT_OPP__
#define __ADDITIONAL_FT_OPP__

typedef struct s_opp
{
    char *ft_operator;
    int (*operation)(int, int);
} t_opp;


int ft_sub(int, int);
int ft_add(int, int);
int ft_mul(int, int);
int ft_div(int, int);
int ft_mod(int, int);
int ft_usage(int, int);


#endif // __ADDITIONAL_FT_OPP__