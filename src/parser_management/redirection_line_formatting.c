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
        write(1, line[i], 1);
        i++;
    }
    while (line[i] != ' ' && line[i] != '\0') {
        write(1, line[i], 1);
        i++;
    }
    return (i);
}

char *get_str_from_part(char *line, int middle_index, int index_to_skip)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (strlen(line) - index_to_skip + 1));
    if (str == NULL) {
        return (NULL);
    }
    memset(str, '\0', (strlen(line) - index_to_skip + 1));
    if (middle_index != 0) {
        strncpy(str, line, middle_index - 1);
        str[middle_index] = ' ';
    }
    strcat(str, &line[middle_index + index_to_skip + 1]);
    return (str);
}
