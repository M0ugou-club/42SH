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
        struct hist_s *next;
    } hist_t;

    extern hist_t *shell_history;

    hist_t *history_init(void);

    void history_add(hist_t *history, const char *command);
    void history_free(hist_t *history);

    void history_print(hist_t *history);
    const char *history_get(hist_t *history, int index);

    hist_t *history_copy(hist_t *history);
#endif //HISTORY_H
