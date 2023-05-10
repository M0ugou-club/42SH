/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_builtin
*/

#include "env.h"
#include "history.h"

int history(env_t *env, char **command_array)
{
    (void) env;
    (void) command_array;

    return (history_print(shell_history));
}