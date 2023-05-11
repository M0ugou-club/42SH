/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** free_env
*/

#include <stdlib.h>
#include "env.h"

int free_env(env_t *env)
{
    if (env == NULL) {
        return (0);
    }
    if (env->next != NULL) {
        free_env(env->next);
    }
    if (env->env_line != NULL) {
        free(env->env_line);
    }
    free(env);
    return (0);
}
