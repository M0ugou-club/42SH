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

    void add_line_in_env(const char *new_line, env_t *env);

    void remove_line_in_env(const char *var, env_t *env);

    int get_tab_len(char **tab);

#endif /* !ENV_UTILS_H_ */
