CC = gcc
FLAGS = -g3 -Wall -Wextra -Werror
I = -I../../libs/libft/includes/ 	# Includes directory
L = -L../../libs/libft/ -lft		# Lib directory
SRC = ft_cat.c
OUT = ft_cat

all:
	$(CC) $(SRC) $(I) $(L) $(FLAGS) -o $(OUT)

clean:
	rm -f $(OUT)

fclean: clean

limit:
	ulimit -s 32

unlimit:
	ulimit -s unlimited

test: $(OUT)
	./$(OUT) test1.txt test2.txt
