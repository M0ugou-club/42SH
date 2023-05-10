/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_shortcut_previous
*/

#include <string.h>

#include "history.h"

void history_shortcut_previous(hist_t *history, char **command)
{
    hist_t *tmp_hist = history_get_end(history);
    int placement = 0;

    for (int i = 0; *command[i]; i++) {
        if (*command[i] == '!') {
            placement--;
        } else {
            break;
        }
    }
    *command = strdup(history_get_command(history, placement));
}