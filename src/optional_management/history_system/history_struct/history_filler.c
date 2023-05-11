/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_filler
*/

#include <string.h>
#include <stdio.h>

#include "history.h"

void history_filler(hist_t *history, char **command)
{
    hist_short_t type = history_shortcut_finder(*command);
    if (!history) {
        history = history_init();
    }
    if (type != NONE) {
        history_shortcut_handler(history, command, type);
    }
    history_set_command(history, *command);
    history_set_next(history, NULL);
    history_set_prev(history->next->prev, history);
    history = history->next;
}