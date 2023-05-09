/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** remove_env
*/

#include <stdlib.h>
#include <string.h>
#include "env.h"

static void free_line(env_t *to_free)
{
    free(to_free->env_line);
    free(to_free);
}

static env_t *node_to_free(env_t *env, char *var)
{
    env_t *tmp = NULL;
    env_t *to_free = NULL;

    tmp = env;
    while (tmp != NULL) {
        if (tmp != NULL
            && strncmp(tmp->env_line, var, strlen(var)) == 0) {
            to_free = tmp;
        }
        tmp = tmp->next;
    }
    return (to_free);
}

static env_t *free_first_node(env_t *env)
{
    env_t *tmp = NULL;

    if (env != NULL && env->next != NULL) {
        tmp = env->next;
        free(env->env_line);
        env->env_line = env->next->env_line;
        env->next = env->next->next;
        free(tmp);
    }
    return (env);
}

static env_t *free_node(env_t *env, env_t *free_tmp)
{
    env_t *tmp = NULL;

    tmp = env;
    if (env == free_tmp) {
        free_first_node(env);
        return (env);
    }
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->next == free_tmp) {
            tmp->next = tmp->next->next;
        }
        if (tmp != NULL) {
            tmp = tmp->next;
        }
    }
    free_line(free_tmp);
    return (env);
}

void remove_line_in_env(char *var, env_t *env)
{
    env_t *free_tmp = NULL;

    if (var == NULL || env == NULL)
        return;
    free_tmp = node_to_free(env, var);
    if (free_tmp == NULL) {
        return;
    }
    env = free_node(env, free_tmp);
}
