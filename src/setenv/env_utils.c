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

    if (env = NULL || var == NULL) {
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

int get_tab_len(char **tab)
{
    int len = 0;

    if (tab == NULL) {
        return -1;
    } else {
        while (tab[len] != NULL) {
            len++;
        }
    }
    return len;
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

    if (env = NULL || new_line == NULL) {
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
}

void remove_line_in_env(const char *var, env_t *env)
{
    env_t *tmp = NULL;
    size_t var_len = 0;

    if (var == NULL || env ==NULL)
        return;
    var_len = strlen(var);
    tmp = env;
    if (strncmp(env->env_line, var, var_len) == 0) {
        env = env->next;
        free(tmp->env_line);
        free(tmp);
    }
    while (tmp->next != NULL) {
        if (tmp->next != NULL && strncmp(tmp->next->env_line, var, var_len) == 0)
            tmp->next = tmp->next->next;
        tmp = tmp->next;
    }
    if (strncmp(tmp->env_line, var, var_len) == 0)
        tmp = NULL;
}