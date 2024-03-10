CC = gcc
FLAGS = -g3 -Wall -Wextra -Werror
I = -I../../libs/libft/includes/ 	# Includes directory
L = -L../../libs/libft/ -lft		# Lib directory
SRC = ft_hexdump.c
OUT = ft_hexdump

all:
	$(CC) $(SRC) $(I) $(L) $(FLAGS) -o $(OUT)

clean:
	rm -f $(OUT)

fclean: clean