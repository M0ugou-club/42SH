/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_shortcut_string
*/

#include <string.h>

#include "history.h"

void history_shortcut_string_contains(hist_t *history, char **command)
{
    char *str = *command + 1;
    char *try = NULL;
    hist_t *tmp_hist = history_get_end(history);

    for (; tmp_hist; tmp_hist = tmp_hist->prev) {
        try = strstr(tmp_hist->command, str);
        if (try) {
            *command = strdup(tmp_hist->command);
            return;
        }
    }
}

void history_shortcut_string_start(hist_t *history, char **command)
{
    char *str = *command + 1;
    int try = 0;
    hist_t *tmp_hist = history_get_end(history);

    for (; tmp_hist; tmp_hist = tmp_hist->prev) {
        try = strncmp(tmp_hist->command, str, strlen(str));
        if (try == 0) {
            *command = strdup(tmp_hist->command);
            return;
        }
    }
}
