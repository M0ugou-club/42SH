/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_shortcut_handler
*/

#include <string.h>

#include "history.h"

static hist_short_handler_a history_shortcut_handler_array[] = {
    {NUMBER, &history_shortcut_number},
    {PREVIOUS, &history_shortcut_previous},
    {STRING_CONTAINS, &history_shortcut_string_contains},
    {STRING_START, &history_shortcut_string_start},
    {NONE, NULL}
};

void history_shortcut_handler(hist_t *history, char **command,
    hist_short_t type)
{
    for (int i = 0; history_shortcut_handler_array[i].type != NONE; i++) {
        if (history_shortcut_handler_array[i].type == type) {
            return (history_shortcut_handler_array[i].handler(
                    history,
                    command));
        }
    }
}