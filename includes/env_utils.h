/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** env_utils
*/

#ifndef ENV_UTILS_H_
    #define ENV_UTILS_H_

    #include "env.h"

    int get_tab_len(char **tab);

    env_t *find_var_in_env(env_t *env, const char *var);

    char *create_new_line(char *var, char *value);

    void add_line_in_env(char *new_line, env_t *env);

    env_t *remove_line_in_env(char *var, env_t *env);

    int get_tab_len(char **tab);

    int my_setenv(env_t *env, char **command_array);

    char *my_getenv(env_t *env, char *to_find);

    void build_setenv_command(env_t *env, char *var, char *str);

    int print_env(env_t *env, char **command_array);

#endif /* !ENV_UTILS_H_ */
