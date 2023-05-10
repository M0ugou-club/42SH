/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** my_exit
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "env.h"
#include "env_utils.h"

int update_return_value(env_t *env, int new_return_value, bool is_exit)
{
    static int return_value = 0;

    if (is_exit) {
        return(return_value);
    } else {
        return_value = new_return_value;
    }
}

void my_exit_builtin(env_t *env, char **command_array)
{
    int return_value = 0;

    if (env == NULL || command_array == NULL) {
        return;
    }
    if (get_tab_len(command_array) != 2 && get_tab_len(command_array) != 1) {
        write(2, "exit: Expression Syntax.\n", 25);
        return;
    }
    return_value = update_return_value(env, 0, true);
    if (command_array[1] != NULL) {
        if (!isdigit(command_array[1])) {
            write(2, "exit: Expression Syntax.\n", 25);
            return;
        }
        return_value = atoi(command_array[1]);
    }
    free_env(env);
    exit(return_value);
}
