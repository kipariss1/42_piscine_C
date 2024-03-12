CC = gcc
FLAGS = -g3 -Wall -Wextra -Werror
I = -I../../libs/libft/includes/ 	# Includes directory
L = -L../../libs/libft/ -lft		# Lib directory
SRC = ft_hexdump.c
OUT = ft_hexdump

all:
	$(CC) $(SRC) $(I) $(L) $(FLAGS) -o $(OUT)

clean:
	find . -type d ! \( -name ".vscode" -o -name . -o -name .. \) -exec rmdir {} \;
	find . -type f ! \( -name $(SRC) -o -name $(OUT) -o -name test1.txt -o -name test2.txt -o -name Makefile \) -exec rm -f {} \;

fclean: clean
	rm -f $(OUT)