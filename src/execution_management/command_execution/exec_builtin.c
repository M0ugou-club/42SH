/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_builtin
*/

#include <string.h>
#include <stddef.h>
#include "builtin.h"
#include "env.h"

static const builtin_t all_builtin[] = {{"cd", &my_cd},
{"env", &print_env},
{"setenv", &my_setenv},
{"unsetenv", &my_unsetenv},
{"exit", NULL},
{"history", &history},
{"echo", &my_echo},
{NULL, NULL}};

int exec_builtin(env_t *env, char **command_array)
{
    int return_value = 0;

    if (command_array == NULL || command_array[COMMAND_INDEX] == NULL) {
        return (-1);
    }
    for (int i = 0; all_builtin[i].builtin != NULL; i++) {
        if (strcmp(all_builtin[i].builtin, command_array[COMMAND_INDEX]) == 0
            && all_builtin[i].action != NULL) {
            return_value = all_builtin[i].action(env, command_array);
            return (return_value);
        }
    }
    return (-1);
}
