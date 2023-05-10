/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** func to write the appropriate path
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

static const size_t size_max = 1024;

static bool is_to_write(void)
{
    if (isatty(STDIN_FILENO))
        return true;
    return false;
}

static char *get_path(void)
{
    char *current_path = NULL;

    current_path = malloc(sizeof(char) * size_max);
    if (current_path == NULL)
        return NULL;
    getcwd(current_path, size_max);
    if (current_path == NULL)
        return NULL;
    return (current_path);
}

int print_path_prompt(void)
{
    char *path_prompt = NULL;

    if (is_to_write() == true) {
        path_prompt = get_path();
        if (path_prompt == NULL)
            return (84);
        write(1, path_prompt, strlen(path_prompt));
        write(1, ":", 1);
        free(path_prompt);
    }
    return (0);
}
