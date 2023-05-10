/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history
*/

#ifndef HISTORY_H
    #define HISTORY_H

    typedef struct hist_s {
        const char *command;
        struct hist_s *next, *prev;
    } hist_t;

    extern hist_t *shell_history;

    hist_t *history_init(void);

    void history_add(hist_t *history, const char *command);
    void history_free(hist_t *history);

    int history_print(hist_t *history);
    int history_short_print(hist_t *history, char *command);

    const char *history_get_command(hist_t *history, int index);
    hist_t *history_get_end(hist_t *history);
    int history_get_size(hist_t *history);

    hist_t *history_copy(hist_t *history);

    void history_filler(hist_t *history, char **command);

    // history shortcuts

    typedef enum hist_short_t {
        NUMBER,
        STRING_START,
        STRING_CONTAINS,
        PREVIOUS,
        NONE = -1
    } hist_short_t;

    typedef struct hist_short_handler_a {
        hist_short_t type;
        void (*handler)(hist_t *history, char **command);
    } hist_short_handler_a;

    hist_short_t history_shortcut_finder(const char *command_line);
    hist_short_t hist_short_set_type(const char *command);
    void history_shortcut_handler(hist_t *history,
                              char **command,
                              hist_short_t type);

    void history_shortcut_number(hist_t *history, char **command);
    void history_shortcut_previous(hist_t *history, char **command);
    void history_shortcut_string_contains(hist_t *history, char **command);
    void history_shortcut_string_start(hist_t *history, char **command);
#endif //HISTORY_H
