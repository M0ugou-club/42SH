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
    if (old) {
        if (command) {
            free(old->command);
        }
        if (old->next) {
            history_free(old->next);
        }
    }
}
