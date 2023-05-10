/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** shell
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ast.h"
#include "unused.h"
#include "tree.h"
#include "env.h"
#include "env_utils.h"
#include "utils.h"

int path_checker(env_t *env)
{
    bool check_path = false;
    env_t *temp = NULL;

    if (!env) {
        return -1
    }
    temp = env;
    while (temp) {
        if (strncmp(temp->env_line, "PATH=", 5) {
            checker_path = true;
        }
        temp = temp->next;
    }
    if (check_path == false) {
        build_setenv_command(env, "PATH", "PATH=/bin:/usr/bin");
    }
    return 0;
}

int loop_sh(env_t *env, char *line)
{
    tree_t *ast = NULL;

    line = str_clear(line);
    ast = parser(line);
    run_ast(ast, env);
    clean_ast(ast);
    return (0);
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
    free(line);
    free_env(my_env);
    return (return_value);
}

int main(UNUSED int ac, UNUSED char **av, char *env[])
{
    int return_value = 0;

    return_value = run_sh(env);
    return (return_value);
}
