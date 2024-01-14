rm *.o
rm *.a

gcc -c *.c
ar rcs libft.a *.o

ranlib libft.a
