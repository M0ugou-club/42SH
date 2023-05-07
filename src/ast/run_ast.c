/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** run_ast
*/

#include <stddef.h>
#include "ast.h"
#include "env.h"

int run_ast(tree_t *ast, env_t *env)
{
    object_t *obj = NULL;

    obj = ast->component;
    obj->action(env, ast);
    if (ast->left_tree != NULL) {
        run_ast(ast->left_tree, env);
    }
    if (ast->right_tree != NULL) {
        run_ast(ast->right_tree, env);
    }
    return (0);
}
