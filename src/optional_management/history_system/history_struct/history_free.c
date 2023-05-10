/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_free
*/

#include <stdlib.h>

#include "history.h"

void history_free(hist_t *old)
{
    hist_t *tmp;

    while (old) {
        tmp = old;
        old = old->next;
        free(tmp->command);
        free(tmp);
    }
}
