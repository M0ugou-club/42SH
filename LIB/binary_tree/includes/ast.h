/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** ast
*/

#ifndef AST_H_
    #define AST_H_

    #include "env.h"

    typedef enum data_type_e {
        SEMI_COL,
        AND,
        OR,
        PIPE,
        DOUBLE_IN,
        SIMPLE_IN,
        DOUBLE_OUT,
        SIMPLE_OUT,
        COMMAND
    } data_type_t;

    typedef struct object_s {
        data_type_t type;
        void (*action) (env_t *env, ast_t *ast, int exec_read, int exec_write);
        void *data;
    } object_t;

#endif /* !AST_H_ */
