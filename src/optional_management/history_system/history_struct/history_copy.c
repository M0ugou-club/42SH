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
        new->command = strdup(tmp->command);
        new->next = history_init();
        new = new->next;
    }
    return (new);
}

