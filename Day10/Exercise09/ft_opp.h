#ifndef FT_OPP_H
#define FT_OPP_H

#include "add_ft_opp.h"

t_opp g_opptab[] =
{
    {"-", &ft_sub},
    {"+", &ft_add},
    {"*", &ft_mul},
    {"/", &ft_div},
    {"%", &ft_mod},
    {"", &ft_usage},
};

#endif // FT_OPP_H
