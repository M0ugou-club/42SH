/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** error_intern
*/

#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int error_exec(char **command_array)
{
    struct stat my_stat;

    if (stat(command_array[0], &my_stat) == -1) {
        write(2, command_array[0], strlen(command_array[0]));
        write(2, ": Command not found.\n", 21);
        return (1);
    }
    if (S_ISDIR(my_stat.st_mode) || access(command_array[0], X_OK) != 0) {
        write(2, "./", 2);
        write(2, command_array[0], strlen(command_array[0]));
        write(2, ": Permission denied.\n", 21);
        return (1);
    }
    return (0);
}
