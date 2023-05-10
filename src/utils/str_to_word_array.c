/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include <string.h>

int count_nb_char(char *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (nb == c) {
            nb++;
        }
    }
    return (nb);
}

int count_nb_word(char *str, char delim)
{
    int nb_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            nb_word++;
        }
    }
    return (nb_word  + 1);
}

char *copy_part(char *str)
{
    char *new_str = NULL;

    if (str == NULL) {
        return (NULL);
    }
    new_str = malloc(sizeof(char) * (strlen(str) + 1));
    if (new_str != NULL) {
        memset(new_str, '\0', strlen(str) + 1);
        new_str = strcpy(new_str, str);
    }
    return (new_str);
}

char **mem_array_set(char **array, char *data, int size)
{
    for (int i = 0; i < size; i++) {
        array[i] = data;
    }
    return (array);
}

char **str_to_word_array(char *str, char *delim)
{
    char *tok = NULL;
    char *copy = NULL;
    char **tab = NULL;
    int nb_word = 0;

    copy = copy_part(str);
    if (copy == NULL)
        return (NULL);
    nb_word = count_nb_word(str, delim[0]);
    tok = strtok(copy, delim);
    tab = malloc(sizeof(char *) * (nb_word + 1));
    tab = mem_array_set(tab, NULL, nb_word + 1);
    if (tab != NULL) {
        for (int i = 0; i < nb_word && tok != NULL; i++) {
            tab[i] = copy_part(tok);
            tok = strtok(NULL, delim);
        }
    }
    free(copy);
    return (tab);
}
