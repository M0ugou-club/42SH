##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

AST = ./src/ast/clean_ast.c \
	  ./src/ast/create_obj.c \
	  ./src/run_ast.c

ENV = ./src/env_management/free_env.c \
	  ./src/env_management/switch_env_array.c

EXECUTION_COMMAND = \
	./src/execution_management/command_execution/error_intern.c \
	./src/execution_management/command_execution/exec_builtin.c \
	./src/execution_management/command_execution/exec_command.c \
	./src/execution_management/command_execution/exec_intern.c

EXECUTION_OPERATOR = \
	./src/execution_management/operator_execution/exec_or_and.c \
	./src/execution_management/operator_execution/exec_pipe.c \
	./src/execution_management/operator_execution/redirection_in_execution.c \
	./src/execution_management/operator_execution/redirection_out_execution.c

PARSER = ./src/parser_management/parser.c \
		 ./src/parser_management/redirection_line_formatting.c

UTILS = ./src/utils/replace_char.c

MAIN = ./src/shell.c

SRC = $(ENV) $(EXECUTION_COMMAND) $(EXECUTION_OPERATOR) $(PARSER) $(UTILS) \
	  $(MAIN)

OBJ = $(SRC:.c=.o)

NAME = 42sh

CFLAGS = 	-W -Wall -Wextra -Iincludes -ILIB/binary_tree/includes \
	-Isrc/execution_management/command_execution/includes

LDFLAGS = 	-L ./LIB/tree.a

$(NAME):     $(OBJ)
		make -C LIB/binary_tree/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:    $(NAME)

clean:
	make -C LIB/binary_tree/ clean
	rm -f $(OBJ)

fclean: clean
	make -C LIB/binary_tree/ fclean
	rm -f $(NAME)
	rm -f *~@
	rm -f #*#

re:    fclean all

.PHONY: all clean fclean re
