/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** redirection_line_formatting
*/

#include <stdlib.h>
#include <string.h>

int get_next_word_index(char *line)
{
    int i = 0;

    while (line[i] == ' ') {
        i++;
    }
    while (line[i] != ' ') {
        i++;
    }
    return (i);
}

char *get_str_from_part(char *line, int middle_index, int index_to_skip,
    char *str)
{
    str = malloc(sizeof(char) * (strlen(line) - index_to_skip));
    if (str == NULL) {
        return (NULL);
    }
    memset(str, '\0', (strlen(line) - index_to_skip));
    strncpy(str, line, middle_index - 1);
    str[middle_index] = ' ';
    strcat(str, &line[middle_index + 1 + index_to_skip]);
    return (str);
}
