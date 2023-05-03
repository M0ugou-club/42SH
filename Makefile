##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =			./src/env_management/free_env.c \
				./src/env_management/switch_env_array.c \
				./src/execution_management/command_execution/error_intern.c \
				./src/execution_management/command_execution/exec_builtin.c \
				./src/execution_management/command_execution/exec_command.c \
				./src/execution_management/command_execution/exec_intern.c \
				./src/execution_management/operator_execution/exec_or_and.c \
				./src/execution_management/operator_execution/exec_pipe.c

OBJ = $(SRC:.c=.o)

NAME = 42sh

CFLAGS = 	-W -Wall -Wextra -Iinclude -Ilib/binary_tree/includes

LDFLAGS = 	-L ./lib/ -ltree

$(NAME):     $(OBJ)
		make -C lib/binary_tree/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:    $(NAME)

clean:
	make -C lib/binary_tree/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/binary_tree/ fclean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re:    fclean all

.PHONY: all clean fclean re
