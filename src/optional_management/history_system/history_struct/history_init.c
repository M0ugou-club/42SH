/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_init
*/

#include <stdlib.h>

#include "history.h"

hist_t *history_init(void)
{
    hist_t *new = malloc(sizeof(hist_t));
    new->command = NULL;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}
