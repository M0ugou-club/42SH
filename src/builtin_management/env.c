/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** env.c
*/

#include <string.h>
#include <unistd.h>
#include "env.h"
#include "unused.h"

int print_env(env_t *env, UNUSED char **command_array)
{
    env_t *tmp = NULL;

    if (!env) {
        return -1;
    }
    tmp = env;
    for (; tmp; tmp = tmp->next) {
        if (tmp->env_line) {
            write(1, tmp->env_line, strlen(tmp->env_line));
            write(1, "\n", 1);
        }
    }
    return 0;
}
