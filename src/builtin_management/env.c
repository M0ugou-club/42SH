/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** env.c
*/

#include <string.h>
#include <unistd.h>
#include "env.h"

int env(env_t *env)
{
    env_t *tmp = NULL;

    if (!env) {
        return -1;
    }
    tmp = env;
    for (; tmp->next; tmp = tmp->next) {
        if (tmp->env_line) {
            write(1, tmp->line, strlen(tmp->line));
            write(1, '\n', 1);
        }
    }
    return 0;
}
