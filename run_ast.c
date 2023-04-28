/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** run_ast
*/

#include <stddef.h>
#include "ast.h"
#include "env.h"

int run_ast(ast_t *ast, env_t *env, int exec_read, int exec_write)
{
    object_t *obj = NULL;

    obj = ast->component;
    obj->action(env, ast, exec_read, exec_write);
    if (ast->left != NULL) {
        run_ast(ast->left, env, exec_read, exec_write);
    }
    if (ast->right != NULL) {
        run_ast(ast->right, env, exec_read, exec_write);
    }
    return (0);
}
