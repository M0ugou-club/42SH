/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** shell
*/

#include <stdio.h>
#include <stddef.h>
#include "ast.h"
#include "tree.h"
#include "env.h"
#include "utils.h"

int loop_sh(env_t *env, char *line)
{
    tree_t *ast = NULL;

    line = strclean(line);
    /*bonus();*/
    parser(line);
    run_ast(ast, env);
    clean_ast(ast);
}

int run_sh(char *env[])
{
    int return_value = 0;
    env_t *my_env = NULL;
    char *line = NULL;
    size_t size = 0;

    my_env = get_env_list(env);
    if (my_env == NULL) {
        return (-1);
    }
    while (getline(&line, &size, stdin) != EOF) {
        replace_char(line, '\n', '\0');
        return_value = loop_sh(my_env, line);
    }
    return (return_value);
}

int main(int ac, char **av, char *env[])
{
    int return_value = 0;

    return_value = run_sh(env);
    return (return_value);
}
