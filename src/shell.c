/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** shell
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "sh.h"
#include "ast.h"
#include "unused.h"
#include "tree.h"
#include "env.h"
#include "env_utils.h"
#include "utils.h"
#include "to_free.h"

int path_checker(env_t *env)
{
    bool check_path = false;
    env_t *temp = NULL;

    if (!env) {
        return -1;
    }
    temp = env;
    while (temp) {
        if (strncmp(temp->env_line, "PATH=", 5) == 0) {
            check_path = true;
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
    to_free_t *memory_struct = NULL;
    char *copy = NULL;
    int return_value = 0;

    copy = str_clear(line);
    if (copy != NULL) {
        ast = parser(copy);
        memory_struct = fill_info(ast, line, copy);
        if (get_ast_error(ast) == 0 && memory_struct != NULL) {
            return_value = run_ast(ast, env, memory_struct);
        }
        clean_ast(ast);
        free(copy);
        free(memory_struct);
    }
    return (return_value);
}

int run_sh(char *env[])
{
    int return_value = 0;
    env_t *my_env = NULL;
    char *line = NULL;
    size_t size = 0;

    my_env = get_env_list(env);
    if (my_env == NULL)
        return (-1);
    path_checker(my_env);
    print_path_prompt();
    while (getline(&line, &size, stdin) != EOF) {
        replace_char(line, '\n', '\0');
        return_value = loop_sh(my_env, line);
        print_path_prompt();
    }
    if (line != NULL)
        free(line);
    free_env(my_env);
    return (return_value);
}
