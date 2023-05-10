/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** str_clean.c
*/

#include <stdlib.h>
#include <string.h>

char *remove_tab(char *buff)
{
    int i = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\t')
            buff[i] = ' ';
        i++;
    }
    return buff;
}

int get_start_buff(char *buff)
{
    int k = 0;

    while (buff[k] == ' ') {
        k++;
    }
    return (k);
}

char *str_clear(char *buff)
{
    char *new_buff = NULL;
    int j = 0;
    int k = 0;

    if (buff == NULL)
        return (NULL);
    buff = remove_tab(buff);
    k = get_start_buff(buff);
    new_buff = malloc(sizeof(char) * (strlen(buff) + 1));
    if (new_buff == NULL)
        return (NULL);
    memset(new_buff, '\0', strlen(buff) + 1);
    for (int i = k; buff[i] != '\0'; i++) {
        if ((buff[i] != ' ') || (buff[i + 1] != ' ' && buff[i + 1] != '\0')) {
            new_buff[j] = buff[i];
            j++;
        }
        k = i;
    }
    return new_buff;
}
