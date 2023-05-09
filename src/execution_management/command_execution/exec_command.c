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
#include "utils.h"

int separate_builtin_intern(env_t *env, char *command)
{
    char *command_cleared = NULL;
    char **command_array = NULL;
    int return_value = 0;

    command_cleared = str_clear(command);
    command_array = str_to_word_array(command_cleared, " ");
    return_value = exec_builtin(env, command_array);
    if (return_value != -1) {
        return (return_value);
    }
    return_value = exec_intern(env, command_array);
    free_tab(command_array);
    free(command_cleared);
    return (return_value);
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
