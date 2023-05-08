/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_get
*/

#include <stdlib.h>

#include "history.h"

const char *history_get(hist_t *history, int index)
{
    hist_t *tmp = history_copy(history);

    if (index < 0)
        return (NULL);
    for (int i = 0; i < index; i++) {
        if (tmp->next == NULL) {
            return (NULL);
        }
        tmp = tmp->next;
    }
    return (tmp->command);
}
