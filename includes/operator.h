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
    #include "tree.h"

    #define INDEX_REDIRECT 4

    typedef struct operator_s {
        char *op;
        int (*action) (env_t *env, tree_t *ast);
        data_type_t type;
    } operator_t;

#endif /* !OPERATOR_H_ */
