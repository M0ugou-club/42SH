/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** env_utils
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "env.h"

env_t *find_var_in_env(env_t *env, const char *var)
{
    env_t *tmp = NULL;
    size_t var_len = 0;

    if (env == NULL || var == NULL) {
        return NULL;
    }
    var_len = strlen(var);
    tmp = env;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (strncmp(var, tmp->env_line, var_len) == 0) {
            return tmp;
        }
    }
    return NULL;
}

char *create_new_line(char *var, char *value)
{
    char *new_line = NULL;

    new_line = malloc(sizeof(char) * (my_strlen(var) + my_strlen(value) + 2));
    if (new_line == NULL) {
        return NULL;
    }
    new_line = my_strcpy(new_line, var);
    new_line = my_strcat(new_line, "=");
    if (value != NULL)
        new_line = my_strcat(new_line, value);
    return (new_line);
}

void add_line_in_env(const char *new_line, env_t *env)
{
    env_t *tmp = NULL;

    if (env == NULL || new_line == NULL) {
        return;
    } else {
        tmp = env;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
    }
    if (new_line == NULL) {
        return;
    }
    tmp->next = malloc(sizeof(env_t));
    if (tmp->next == NULL) {
        return;
    }
    tmp->next->env_line = new_line;
    tmp->next->next = NULL;
}

static void free_line(env_t *to_free)
{
    free(to_free->env_line);
    free(to_free);
}

void remove_line_in_env(const char *var, env_t *env)
{
    env_t *tmp = NULL;
    env_t *free_tmp = NULL;

    if (var == NULL || env == NULL)
        return;
    tmp = env;
    if (strncmp(env->env_line, var, strlen(var)) == 0) {
        env = env->next;
        free_line(tmp);
    }
    while (tmp->next != NULL) {
        if (tmp->next != NULL &&
            strncmp(tmp->next->env_line, var, strlen(var)) == 0)
            free_tmp = tmp->next;
            tmp->next = tmp->next->next;
            free_line(free_tmp);
        tmp = tmp->next;
    }
    if (strncmp(tmp->env_line, var, strlen(var)) == 0)
        free_line(tmp);
}