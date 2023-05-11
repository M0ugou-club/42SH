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

static const char ERROR1[28] = "setenv: Too many arguments.\n";
static const char ERROR2[48] = "setenv: Variable name must begin with a letter.\n";
static const char ERROR3[61] = "setenv: Variable name must contain alphanumeric \
characters.\n";
static const int FIRST_ARG = 1;
static const int SEC_ARG = 2;

static bool error(char **arr)
{
    if (get_tab_len(arr) > 3) {
        write(2, ERROR1, sizeof(ERROR1));
        return true;
    } else if (get_tab_len(arr) == 1) {
        return false;
    }
    if ((arr[1][0] < 'a' || arr[1][0] > 'z')
        && (arr[1][0] < 'A' || arr[1][0] > 'Z')) {
        write(2, ERROR2, strlen(ERROR2));
        return (true);
    }
    for (int i = 1; arr[1][i] != '\0'; i++) {
        if (((arr[1][i] < 'a' || arr[1][i] > 'z' ) && (arr[1][i] < 'A'
            || arr[1][i] > 'Z') && (arr[1][i] < '0' || arr[1][i] > '9'))) {
            write(2, ERROR3, strlen(ERROR3));
            return (true);
        }
    }
    return false;
}

int my_setenv(env_t *env, char **command_array)
{
    int tab_len = 0;
    char *line = NULL;
    env_t *tmp = NULL;

    if (env == NULL || command_array == NULL || error(command_array) == true)
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
