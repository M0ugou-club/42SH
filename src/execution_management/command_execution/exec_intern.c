/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_intern
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "sh.h"
#include "ast.h"
#include "builtin.h"
#include "env.h"
#include "utils.h"

int execution(char **command_array, char **my_env)
{
    int pid = 0;
    int wstatus = 0;

    if (error_exec() == 1) {
        return (1);
    }
    pid = fork();
    if (pid == -1) {
        return (-1);
    }
    if (pid != 0) {
        waitpid(pid, &wstatus, 0);
    } else {
        if (execve(command_array[COMMAND_INDEX], command_array, my_env) == -1) {
            exit(-1);
        }
    }
    return (wstatus);
}

int get_function(char **path_array, char **command_array)
{
    char *new_command = NULL;

    for (int i = 0; path_array[i] != NULL; i++) {
        new_command = malloc(sizeof(char) * (strlen(path_array[i]) +
            strlen(command_array[COMMAND_INDEX]) + strlen("/") + 1));
        if (new_command == NULL)
            return (-1);
        strcpy(new_command, path_array[i]);
        strcat(new_command, "/");
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
            path_array = str_to_word_array(&tmp->env_line[5], ":");
        }
        tmp = tmp->next;
    }
    return (path_array);
}

int exec_intern(env_t *env, char **command_array)
{
    char **path_array = NULL;
    char **my_env = NULL;

    path_array = get_path_array(env);
    if (path_array == -1)
        return (-1);
    get_function(path_array, command_array);
    my_env = get_env_array(env);
    if (my_env == NULL) {
        return (-1);
    }
    execution(command_array, my_env);
    return (0);
}
