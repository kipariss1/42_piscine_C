CC = gcc
CFLAGS = -c -Wall -g3

SRC_FILES=$(wildcard srcs/*.c)	# listing all .c files in srcs
INCLUDE_FLAG=-I./includes/

NAME=libft.a		# defining output

all : $(NAME) clean		# main target of makefile
	$(info main target)

obj_files : $(SRC_FILES)
	$(info generating object files)
	$(CC) $(CFLAGS) $(SRC_FILES) $(INCLUDE_FLAG) 

$(NAME) : obj_files
	$(info adding generated .o to archive)
	ar rsc $(NAME) *.o

clean:
	$(info cleaning)
	rm -f *.o	

fclean: clean
	$(info cleaning good)
	rm -f $(NAME)

re: fclean $(NAME)
	rm -f *.o