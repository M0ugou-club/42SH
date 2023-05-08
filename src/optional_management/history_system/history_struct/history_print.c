/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_print
*/

#include <stdlib.h>
#include <unistd.h>

#include "history.h"

void *history_print(hist_t *history)
{
    hist_t *tmp = history_copy(history);
    if (!tmp)
        return (NULL);

    for (int i = 0; tmp; i++) {
        my_put_nbr(i);
        write(1, "\t", 1);
        write(1, tmp->command, my_strlen(tmp->command));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}
