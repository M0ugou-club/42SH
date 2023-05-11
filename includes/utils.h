/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    char *replace_char(char *str, char to_find, char to_replace);
    char *str_clear(char *buff);
    char **str_to_word_array(char *str, char *delim);
    void free_tab(char **tab);

#endif /* !UTILS_H_ */
