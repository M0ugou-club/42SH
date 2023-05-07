/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_command
*/

#include <unistd.h>
#include <stddef.h>
#include "sh.h"
#include "ast.h"
#include "tree.h"
#include "env.h"

int separate_builtin_intern(env_t *env, char *command)
{
    char *command_cleared = NULL;
    char **command_array = NULL;

    command_cleared = my_strclear(command);
    command_array = my_str_to_word_array(command_cleared);
    if (exec_builtin(env, command_array) == -1) {
        return (0);
    }
    exec_intern(env, command_array);
    return (0);
}

int exec_command(env_t *env, tree_t *ast)
{
    char *command = NULL;
    object_t *obj = ast->component;
    int return_value = 0;

    if (obj != NULL) {
        command = obj->data;
        if (command != NULL) {
            return_value = separate_builtin_intern(env, command);
            return (return_value);
        }
    }
    return (-1);
}
