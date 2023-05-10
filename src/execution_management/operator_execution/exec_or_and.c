/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_or
*/

#include <stddef.h>
#include "ast.h"
#include "env.h"

int exec_or(env_t *env, tree_t *ast)
{
    int return_value = 0;

    if (ast->left_tree != NULL) {
        return_value = run_ast(ast->left_tree, env);
    }
    if (return_value != 0) {
        if (ast->right_tree != NULL) {
            run_ast(ast->right_tree, env);
        }
    }
    clean_ast(ast->left_tree);
    ast->left_tree = NULL;
    clean_ast(ast->right_tree);
    ast->right_tree = NULL;
    return (return_value);
}

int exec_and(env_t *env, tree_t *ast)
{
    int return_value = 0;

    if (ast->left_tree != NULL) {
        return_value = run_ast(ast->left_tree, env);
    }
    if (return_value == 0) {
        if (ast->right_tree != NULL) {
            run_ast(ast->right_tree, env);
        }
    }
    clean_ast(ast->left_tree);
    ast->left_tree = NULL;
    clean_ast(ast->right_tree);
    ast->right_tree = NULL;
    return (return_value);
}
