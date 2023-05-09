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

int my_segfault(int wstatus)
{
    int signal = 0;

    if (WIFEXITED(wstatus))
        return (WEXITSTATUS(wstatus));
    signal = WTERMSIG(wstatus);
    if (wstatus == 136) {
        write(2, "Floating exception (core dumped)\n", 33);
    } else {
        write(2, strsignal(signal), strlen(strsignal(signal)));
        write(2, "\n", 1);
    }
    return (wstatus);
}

int execution(char **command_array, char **my_env)
{
    int pid = 0;
    int wstatus = 0;
    int return_value = 0;

    if (error_exec(command_array) == 1) {
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
    return_value = my_segfault(wstatus);
    return (return_value);
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
    int return_value = 0;

    path_array = get_path_array(env);
    if (path_array == NULL)
        return (-1);
    get_function(path_array, command_array);
    my_env = get_env_array(env);
    if (my_env == NULL) {
        return (-1);
    }
    return_value = execution(command_array, my_env);
    free_tab(path_array);
    free_tab(my_env);
    return (return_value);
}
