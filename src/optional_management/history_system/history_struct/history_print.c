/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** history_print
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "history.h"

static char *my_itoa(int i)
{
    int size = 0;
    int tmp = i;
    char *str;

    for (; tmp > 0; size++)
        tmp /= 10;
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    str[size] = '\0';
    for (int j = size - 1; j >= 0; j--) {
        str[j] = i % 10 + '0';
        i /= 10;
    }
    return (str);
}

static void print_index(int i)
{
    char *index = my_itoa(i);
    write(1, index, strlen(index));
    free(index);
}

int history_print(hist_t *history)
{
    hist_t *tmp = history_copy(history);
    if (!tmp) {
        return (84);
    }

    for (int i = 0; tmp; i++) {
        print_index(i);
        write(1, "\t", 1);
        write(1, tmp->command, strlen(tmp->command));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    return (0);
}
