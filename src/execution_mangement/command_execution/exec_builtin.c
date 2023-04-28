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

static const builtin_t all_builtin[] = {{"cd", NULL},
{"env", NULL},
{"setenv", NULL},
{"unsetenv", NULL},
{"exit", NULL},
{"echo", NULL},
{NULL, NULL}};

int exec_builtin(env_t *env, char **command_array)
{
    if (command_array == NULL || command_array[COMMAND_INDEX] == NULL) {
        return (-1);
    }
    for (int i = 0; all_builtin[i].builtin != NULL; i++) {
        if (strcmp(all_builtin[i].builtin, command_array[COMMAND_INDEX])) {
            all_builtin[i].action(env, command_array);
            return (0);
        }
    }
    return (-1);
}
