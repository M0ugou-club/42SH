/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** get_tab_len
*/

#include "stdlib.h"

int get_tab_len(char **tab)
{
    int len = 0;

    if (tab == NULL) {
        return -1;
    } else {
        while (tab[len] != NULL) {
            len++;
        }
    }
    return len;
}
