/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** setenv
*/

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "env_utils.h"

static const char ERROR[28] = "setenv: Too many arguments.\n";
static const int FIRST_ARG = 1;
static const int SEC_ARG = 2;

static bool error(env_t *env, char **command_array)
{
    if (env == NULL || command_array == NULL) {
        return true;
    }
    if (get_tab_len(command_array) > 3) {
        write(2, ERROR, sizeof(ERROR));
        return true;
    }
    return false;
}

int my_setenv(env_t *env, char **command_array)
{
    int tab_len = 0;
    char *line = NULL;
    env_t *tmp = NULL;

    if (error(env, command_array))
        return (1);
    tab_len = get_tab_len(command_array);
    if (tab_len == 1) {
        print_env(env, command_array);
        return (0);
    }
    line = create_new_line(command_array[FIRST_ARG], command_array[SEC_ARG]);
    tmp = find_var_in_env(env, command_array[FIRST_ARG]);
    if (tmp == NULL) {
        add_line_in_env(line, env);
    } else {
        free(tmp->env_line);
        tmp->env_line = line;
    }
    return (0);
}
