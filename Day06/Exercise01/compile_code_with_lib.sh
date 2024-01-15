# script for compiling code with static (.a) library
# 1) "-L" flag is for location for searching linked library, "." - is current dir in which linked lib will be searched
# 2) "-lft" is the flag - name of the lib "libft.a", lib is thrown out,  .a is thrown out, -l is the flag

gcc ft_print_program_name.c -L. -lft -o a.out && 
chmod a+x a.out 
