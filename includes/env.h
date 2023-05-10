/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** env
*/

#ifndef ENV_H_
    #define ENV_H_

    typedef struct env_s {
        char *env_line;
        struct env_s *next;
    } env_t;

    char **get_env_array(env_t *env);
    env_t *get_env_list(char **env);
    int free_env(env_t *env);

#endif /* !ENV_H_ */
