/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** get_env_array
*/

#include <stdlib.h>
#include <string.h>
#include "env.h"

int get_list_len(env_t *env)
{
    int len = 0;
    env_t *tmp = env;

    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return (len);
}

char **get_env_array(env_t *env)
{
    char **env_array = NULL;
    int len = 0;
    env_t *tmp = env;

    len = get_list_len(env);
    env_array = malloc(sizeof(char *) * (len + 1));
    if (env_array == NULL)
        return (NULL);
    env_array[len] = NULL;
    for (int i = 0; i < len && tmp != NULL; i++, tmp = tmp->next) {
        env_array[i] = malloc(sizeof(char) * (strlen(tmp->env_line) + 1));
        memset(env_array[i], '\0', strlen(tmp->env_line) + 1);
        if (env_array[i] == NULL)
            return (NULL);
        strcpy(env_array[i], tmp->env_line);
    }
    return (env_array);
}
