/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** builtin
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_
    #define COMMAND_INDEX 0

    #include "env.h"

    typedef struct builtin_s {
        char *builtin;
        int (* action) (env_t *env, char **command_array);
    } builtin_t;

    int my_cd(env_t *env, char **command_array);
    int my_setenv(env_t *env, char **command_array);
    int print_env(env_t *env, char **command_array);
    int my_unsetenv(env_t *env, char **command_array);

#endif /* !BUILTIN_H_ */
