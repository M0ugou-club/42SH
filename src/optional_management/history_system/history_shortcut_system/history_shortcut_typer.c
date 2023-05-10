/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_shortcut_typer
*/

#include <string.h>
#include <stdlib.h>

#include "history.h"

hist_short_t hist_short_set_type(const char *command)
{
    char *tmp = strdup(command + 1);

    if (atoi(tmp) == 0) {
        return (NUMBER);
    } else if (strncmp(tmp, "!", 1) == 0) {
        return (PREVIOUS);
    } else if (strncmp(tmp, "?", 1) == 0) {
        return (STRING_CONTAINS);
    } else {
        return (STRING_START);
    }
    return (NONE);
}