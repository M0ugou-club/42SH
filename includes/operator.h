/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** operator
*/

#ifndef OPERATOR_H_
    #define OPERATOR_H_

    #include "env.h"
    #include "ast.h"

    #define INDEX_REDIRECT 4

    typedef struct operator_s {
        char *op;
        void (*action) (env_t *env, ast_t *ast, int exec_read, int exec_write);
    } operator_t;

#endif /* !OPERATOR_H_ */
