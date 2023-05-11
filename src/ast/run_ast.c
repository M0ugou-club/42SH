/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** run_ast
*/

#include <stddef.h>
#include <stdbool.h>
#include "ast.h"
#include "env_utils.h"
#include "env.h"
#include "to_free.h"

int run_ast(tree_t *ast, env_t *env, to_free_t *memory_struct)
{
    object_t *obj = NULL;
    int return_value = 0;

    if (ast != NULL) {
        obj = ast->component;
    }
    if (obj != NULL) {
        if (obj->action != NULL) {
            return_value = obj->action(env, ast, memory_struct);
        }
        if (ast->left_tree != NULL) {
            return_value = run_ast(ast->left_tree, env, memory_struct);
        }
        if (ast->right_tree != NULL) {
            return_value = run_ast(ast->right_tree, env, memory_struct);
        }
    }
    update_return_value(return_value, false);
    return (return_value);
}
