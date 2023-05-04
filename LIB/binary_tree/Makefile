##
## EPITECH PROJECT, 2023
## LIB
## File description:
## Makefile
##

SRC	=	src/create_tree.c \
		src/print_tree.c \
		src/clean_tree.c \
		AST/create_obj.c

OBJ = $(SRC:.c=.o)

NAME = tree.a

CFLAGS = -W -Wall -Wextra -I./includes

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			mv $(NAME) ../

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re:    fclean all

.PHONY: all clean fclean re
