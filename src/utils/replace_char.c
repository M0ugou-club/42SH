/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** replace_last_char
*/

char *replace_char(char *str, char to_find, char to_replace)
{
    int i = 0;

    while (str[i] != to_find) {
        i++;
    }
    str[i] = to_replace;
    return (str);
}
