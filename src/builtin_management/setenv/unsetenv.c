/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** unsetenv
*/

#include <stdlib.h>
#include <stdbool.h>
#include "env_utils.h"

static const char ERROR[29] = "unsetenv: Too few arguments.\n";

static bool error(env_t *env, char **command_array)
{
    if (env == NULL || command_array == NULL) {
        return true;
    }
    if (get_tab_len(command_array) == 1) {
        write(2, ERROR, sizeof(ERROR));
        return true;
    }
    return false;
}

int my_unsetenv(env_t *env, char **command_array)
{
    if (error(env, command_array)) {
        return (1);
    }
    for (int i = 1; command_array[i] != NULL; i++) {
        remove_line_in_env(command_array[i], env);
    }
    return (0);
}