/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** env.c
*/

#include <stdio.h>
#include "env.h"

int env(env_t *env)
{
    env_t *tmp = NULL;

    if (!env) {
        return -1;
    }
    tmp = env;
    for (; tmp->next; tmp = tmp->next) {
        if (tmp->env_line)
            printf("%s\n", tmp->env_line);
    }
}
