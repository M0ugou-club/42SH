/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_intern
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sh.h"
#include "ast.h"
#include "builtin.h"
#include "env.h"

int execution(char **command_array, char **my_env)
{
    if (error_exec() == 1) {
        exit(1);
    }
    if (execve(command_array[COMMAND_INDEX], command_array, my_env) == -1) {
        exit(1);
    }
    return (0);
}

int get_function(char **path_array, char **command_array)
{
    char *new_command = NULL;

    for (int i = 0; path_array[i] != NULL; i++) {
        new_command = malloc(sizeof(char) * (strlen(path_array[i]) +
            strlen(command_array[COMMAND_INDEX]) + 1));
        if (new_command == NULL)
            return (-1);
        strcpy(new_command, path_array[i]);
        strcat(new_command, command_array[COMMAND_INDEX]);
        if (access(new_command, 0) == 0) {
            free(command_array[COMMAND_INDEX]);
            command_array[COMMAND_INDEX] = new_command;
        } else {
            free(new_command);
        }
    }
    return (0);
}

char **get_path_array(env_t *env)
{
    env_t *tmp = env;
    char **path_array = NULL;

    while (tmp != NULL) {
        if (strncmp(tmp->env_line, "PATH=", 5) == 0) {
            path_array = str_to_word_array(&tmp->env_line[5]);
        }
        tmp = tmp->next;
    }
    return (path_array);
}

int exec_intern(env_t *env, char **command_array)
{
    return (0);
}
