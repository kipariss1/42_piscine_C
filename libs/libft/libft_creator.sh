rm *.o
rm *.a

gcc -c srcs/*.c
ar rcs libft.a srcs/*.o

ranlib libft.a
