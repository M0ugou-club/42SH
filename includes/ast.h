/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** ast
*/

#ifndef AST_H_
    #define AST_H_

    #include "env.h"
    #include "tree.h"

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
        int (*action) (env_t *env, tree_t *ast);
        void *data;
    } object_t;

    tree_t *parser(char *line);
    void clean_ast(tree_t *tree);
    int run_ast(tree_t *ast, env_t *env);
    tree_t *create_obj(int (*action) (env_t *env, tree_t *ast), void *data,
        data_type_t type);
    int get_ast_error(tree_t *ast);

#endif /* !AST_H_ */
