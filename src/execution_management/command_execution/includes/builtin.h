/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** builtin
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_

    #include "env.h"

    #define COMMAND_INDEX 0

    typedef struct builtin_s {
        char *builtin;
        int (* action) (env_t *env, char **command_array);
    } builtin_t;

#endif /* !BUILTIN_H_ */
