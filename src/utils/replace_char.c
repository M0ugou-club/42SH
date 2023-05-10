/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** replace_last_char
*/

#include <stddef.h>

char *replace_char(char *str, char to_find, char to_replace)
{
    int i = 0;

    if (str == NULL) {
        return (NULL);
    }
    while (str[i] != to_find) {
        if (str[i] == '\0') {
            return (str);
        }
        i++;
    }
    str[i] = to_replace;
    return (str);
}
