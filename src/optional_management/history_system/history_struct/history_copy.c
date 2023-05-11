/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_copy
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "history.h"

hist_t *history_copy(hist_t *history)
{
    hist_t *new = history_init();

    for (hist_t *tmp = history; tmp; tmp = tmp->next) {
        if (tmp->command) {
            history_set_command(new, strdup(tmp->command));
        } else {
            history_set_command(new, NULL);
        }
        history_set_next(new, history_init());
        history_set_prev(new->next->prev, new);
        new = new->next;
    }
    return (new);
}

