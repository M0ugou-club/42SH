/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** get_env_array
*/

#include <stdlib.h>
#include <string.h>
#include "env.h"

static int get_list_len(env_t *env)
{
    int len = 0;
    env_t *tmp = env;

    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return (len);
}

static char *copy_line(char const *copy)
{
    char *line = NULL;

    line = malloc(sizeof(char) * (strlen(copy) + 1));
    if (line == NULL)
        return (NULL);
    memset(line, '\0', strlen(copy) + 1);
    strcpy(line, copy);
    return (line);
}

char **get_env_array(env_t *env)
{
    char **env_array = NULL;
    int i = 0;
    int len = 0;
    env_t *tmp = env;

    len = get_list_len(env);
    env_array = malloc(sizeof(char *) * (len + 1));
    if (env_array == NULL)
        return (NULL);
    env_array[len] = NULL;
    while (i < len && tmp != NULL) {
        env_array[i] = copy_line(tmp->env_line);
        if (env_array[i] == NULL)
            return (NULL);
        i++;
        tmp = tmp->next;
    }
    return (env_array);
}

env_t *get_env_list(char **env)
{
    env_t *my_env = NULL;
    env_t *tmp = NULL;
    env_t *tmp2 = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        tmp = malloc(sizeof(env_t));
        if (tmp == NULL)
            return (NULL);
        if (tmp2 != NULL) {
            tmp2->next = tmp;
        }
        tmp->next = NULL;
        tmp->env_line = copy_line(env[i]);
        if (tmp->env_line == NULL)
            return (NULL);
        if (my_env == NULL)
            my_env = tmp;
        tmp2 = tmp;
    }
    return (my_env);
}
