##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =			./src/main.c \

OBJ = $(SRC:.c=.o)

NAME = 42sh

CFLAGS = 	-W -Wall -Wextra -Iinclude -Ilib/ecs/includes

LDFLAGS = 	-L ./lib/my/ -lmy

$(NAME):     $(OBJ)
		make -C lib/ecs/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:    $(NAME)

clean:
	make -C lib/ecs/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/ecs/ fclean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re:    fclean all

.PHONY: all clean fclean re
