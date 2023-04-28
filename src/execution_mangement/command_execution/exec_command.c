/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_command
*/

#include <unistd.h>
#include <stddef.h>
#include "ast.h"
#include "env.h"

int separate_builtin_intern(env_t *env, char *command, int exec_write)
{
    char *command_cleared = NULL;
    char **command_array = NULL;

    command_cleared = my_strclear(command);
    command_array = my_str_to_word_array(command_cleared);
    if (exec_builtin() == -1) {
        return (0);
    }
    exec_inter();
    return (0);
}

int exec_command(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    char *command = NULL;
    object_t *obj = ast->component;
    int return_value = 0;

    if (obj != NULL) {
        command = obj->data;
        if (command != NULL) {
            dup2(exec_read, STDIN_FILENO);
            return_value = separate_builtin_intern(env, command, exec_write);
            return (return_value);
        }
    }
    return (-1);
}
