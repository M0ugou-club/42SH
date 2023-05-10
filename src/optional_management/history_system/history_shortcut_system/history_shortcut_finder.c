/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_shortcut_finder
*/

#include <string.h>

#include "history.h"

hist_short_t history_shortcut_finder(const char *command_line)
{
    if (command_line[0] != '!')
        return (NONE);
    return (hist_short_set_type(command_line));
}
