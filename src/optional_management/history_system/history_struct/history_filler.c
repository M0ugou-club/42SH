/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_filler
*/

#include "history.h"

void *history_filler(hist_t *history, char *command)
{
    hist_t *new = NULL;
    if (!history)
        history = history_init();
    new = history_init();
    if (!new)
        return (NULL);
    new->command = my_strdup(command);
    new->next = history;
    history = new;
}