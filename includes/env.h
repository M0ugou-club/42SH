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

#endif /* !ENV_H_ */
