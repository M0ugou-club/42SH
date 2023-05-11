/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_set
*/

#include <string.h>

#include "history.h"

void history_set_command(hist_t *history, char *command)
{
    if (command)
        history->command = strdup(command);
    else
        history->command = NULL;
}

void history_set_next(hist_t *history, hist_t *next)
{
    if (next)
        history->next = next;
    else
        history->next = history_init();
}

void history_set_prev(hist_t *history, hist_t *prev)
{
    if (prev)
        history->prev = prev;
    else
        history->prev = history_init();
}
