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

static const int SETENV_ARGS_NBR = 4;

void build_setenv_command(char **env, char *var, char *str)
{
    char **command_array = NULL;

    command_array = malloc(sizeof(char *) * SETENV_ARGS_NBR);
    if (command_array == NULL) {
        return;
    }
    command_array[0] = strdup("setenv");
    command_array[1] = strdup(var);
    command_array[2] = strdup(str);
    command_array[3] = NULL;
    my_setenv(env, command_array);
    free(command_array[2]);
    free(command_array[1]);
    free(command_array[0]);
    free(command_array);
}

char *my_getenv(env_t *env, char *to_find)
{
    env_t *line = NULL;
    char *line_str = NULL;

    line = find_var_in_env(env, to_find);
    if (line == NULL) {
        return NULL;
    }
    line_str = malloc(sizeof(char) * strlen(line->env_line));
    if (line_str == NULL) {
        return NULL;
    }
    memset(line_str, '\0', strlen(line->env_line));
    line_str = strcpy(line_str, &line->env_line[strlen(to_find) +
        strlen("=")]);
    return (line_str);
}
