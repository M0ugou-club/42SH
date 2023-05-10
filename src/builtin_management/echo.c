/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** echo.c
*/

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "env.h"

static bool check_flag(char **command_array)
{
    bool flag = false;

    for (int i = 0; command_array[i] != NULL; i++) {
        if (strcmp(command_array[i], "-n") == 0) {
            flag = true;
        }
    }
    return flag;
}

static void prompt_echo(char **command_array, bool flag, int i)
{
    write(1, command_array[i], strlen(command_array[i]));
    if (command_array[i + 1] == NULL && flag == false) {
        write(1, "\n", 1);
    } else if (strcmp(command_array[i + 1], "-n") != 0) {
        write(1, " ", 1);
    }
}

int my_echo(env_t *env , char **command_array)
{
    bool flag = false;

    if (!command_array || !env) {
        return -1;
    }
    flag = check_flag(command_array);
    for (int i = 1; command_array[i] != NULL; i++) {
        if (strcmp(command_array[i], "-n") != 0) {
            prompt_echo(command_array, flag, i);
        }
    }
    return 0;
}
