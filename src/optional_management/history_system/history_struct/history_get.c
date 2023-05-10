/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_get
*/

#include <stdlib.h>

#include "history.h"

hist_t *history_get_end(hist_t *history)
{
    hist_t *tmp = history_copy(history);

    if (!tmp)
        return (NULL);
    for (; tmp->next; tmp = tmp->next);
    return (tmp);
}

int history_get_size(hist_t *history)
{
    hist_t *tmp = history_copy(history);
    int size = 0;

    if (!tmp)
        return (0);
    for (; tmp; tmp = tmp->next)
        size++;

    return (size);
}

const char *history_get_command(hist_t *history, int index)
{
    hist_t *tmp = history_copy(history);
    int size = history_get_size(history);

    if (index < 0) {
        for (int i = size; i != index && tmp->next; i--) {
            tmp = tmp->next;
        }
    } else if (index >= 0) {
        for (int i = 0; i != index && tmp->next; i++) {
            tmp = tmp->next;
        }
    }

    return (tmp->command);
}
