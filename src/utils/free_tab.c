/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** free_tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != '\0'; i++) {
        free(tab[i]);
    }
    free(tab);
}
