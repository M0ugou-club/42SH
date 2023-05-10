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

char *get_var_complete(char *var)
{
    char *copy = NULL;

    copy = malloc(sizeof(char) * (strlen(var) + 2));
    memset(copy, '\0', strlen(var) + 2);
    strcpy(copy, var);
    strcat(copy, "=");
    return(copy);
}

env_t *find_var_in_env(env_t *env, const char *var)
{
    env_t *tmp = NULL;
    size_t var_len = 0;
    char *copy = NULL;

    if (env == NULL || var == NULL)
        return NULL;
    copy = get_var_complete(var);
    if (copy == NULL)
        return (NULL);
    var_len = strlen(copy);
    tmp = env;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (strncmp(tmp->env_line, copy, var_len) == 0) {
            free(copy);
            return tmp;
        }
    }
    free(copy);
    return NULL;
}

char *create_new_line(char *var, char *value)
{
    char *new_line = NULL;
    int len = 0;

    len = strlen(var) + 2;
    if (value != NULL) {
        len += strlen(value);
    }
    new_line = malloc(sizeof(char) * (len));
    if (new_line == NULL) {
        return NULL;
    }
    memset(new_line, '\0', len);
    new_line = strcpy(new_line, var);
    new_line = strcat(new_line, "=");
    if (value != NULL)
        new_line = strcat(new_line, value);
    return (new_line);
}

void add_line_in_env(char *new_line, env_t *env)
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
