/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** str_clean.c
*/

#include "my.h"
#include <stdlib.h>

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

char *end_the_buff(char *buff, char *new_buff, int j, int k)
{
    if (buff[k + 1] != ' ' && buff[k + 1] != '\t') {
        new_buff[j] = buff[k + 1];
        new_buff[j + 1] = '\0';
    } else
        new_buff[j] = '\0';
    return new_buff;
}

char *str_clean(char *buff, int len)
{
    char *new_buff = NULL;
    int j = 0;
    int k = 0;
    if (buff[len - 1] == '\n')
        buff[len - 1] = '\0';
    new_buff = malloc(sizeof(char) * (len + 1));
    while (buff[k] == ' ' || buff[k] == '\t')
        k++;
    for (int i = k; buff[i + 1] != '\0'; i++) {
        if ((buff[i] != ' ' && buff[i] != '\t')
        || (buff[i + 1] != ' ' && buff[i + 1] != '\t')) {
            new_buff[j] = buff[i];
            j++;
        }
        k = i;
    }
    new_buff = end_the_buff(buff, new_buff, j, k);
    free(buff);
    new_buff = remove_tab(new_buff);
    return new_buff;
}
