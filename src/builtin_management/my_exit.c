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


void my_exit_builtin(env_t *env, char **command_array)
{
    if (get_tab_len(command_array) != 2 || isdigit(command_array[1])) {
        write(2, "exit: Expression Syntax.\n", 25);
        return;
    }
    my_exit(env, 0, true);
}

void my_exit(env_t *env, int new_return_value, bool is_exit)
{
    static int return_value = 0;

    if (is_exit) {
        free_env(env);
        exit(return_value);
    } else {
        return_value = new_return_value;
    }
}