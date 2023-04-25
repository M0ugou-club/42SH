/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** ast
*/

#ifndef AST_H_
    #define AST_H_

    typedef struct ast_s ast_t;
    typedef struct env_s env_t;

    struct ast_s {
        void (*action) ()
        char *command;
        ast_t *left;
        ast_t *right;
    } ast_t;

    struct env_s {
        char *env_line;
        env_t *next;
    } env_t;

#endif /* !AST_H_ */
