#ifndef __LIBFT_H__
#define __LIBFT_H__

void ft_putchar(char c);
void ft_putstr(char* str);
int ft_strlen(char *str);
char* ft_strcat(char *dest, char *src);
int ft_strcmp(char* s1, char* s2);
char* ft_strcpy(char *dest, char *src);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
char* ft_strncat(char *dest, char *src, int n);
char* ft_strncpy(char* dest, char* src, unsigned int n);
void ft_swap(int *a, int *b);
void ft_initstr(char *str, unsigned int strlen);
int ft_iterative_power(int nb, int power);
int ft_str_to_int(char *str);
void ft_int_to_str(char *buffer, int convert_from, int len_convert_from);

#endif