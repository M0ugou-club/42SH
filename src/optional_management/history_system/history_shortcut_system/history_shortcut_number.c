/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_shortcut_number
*/

#include <string.h>
#include <stdlib.h>

#include "history.h"

void history_shortcut_number(hist_t *history, char **command)
{
    int nb = atoi(*command + 1);

    *command = (char *)history_get_command(history, nb);
}
