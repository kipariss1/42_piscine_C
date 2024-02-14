CC = gcc
CFLAGS = -Wall

SRC_FILES=$(wildcard ../../libst/libft/*.c)	# listing all .c files in dir
OBJ_FILES=$(SRC:.c=.o)	# substituting .c for .o
NAME=libft.a		# defining output

all: $(NAME) clean	# checks if libft.a exists, if yes - move to the next line

clean:
	rm -f $(OBJ_FILES)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES) : $(SRC_FILES)
	$(CC) -c $(CFLAGS) $(SRC_FILES) 

# TODO: finish with all the requirments from task	
	