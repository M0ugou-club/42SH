/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_builtin
*/

#include <stddef.h>

#include "env.h"
#include "history.h"

hist_t *shell_history = NULL;

int my_history(env_t *env, char **command_array)
{
    (void) env;
    (void) command_array;

    return (history_print(shell_history));
}