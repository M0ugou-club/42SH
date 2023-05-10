/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** ast_error
*/

#include <stddef.h>
#include "ast.h"
#include "tree.h"

int error_in_and_or(tree_t *ast, object_t *obj)
{
    if (ast->left_tree == NULL || ast->right_tree == NULL) {
        write(2, "Invalid null command.\n", 22);
        return (-1);
    }
    return (0);
}

int error_in_redirect(tree_t *ast, object_t *obj)
{
    object_t *left_obj = NULL;

    if (ast->left_tree == NULL || ast->right_tree == NULL) {
        write(2, "Missing name for redirect.\n", 28);
        return (-1);
    }
    left_obj = ast->left_tree->component;
    if (left_obj != NULL) {
        if (left_obj->type < COMMAND && left_obj >= PIPE) {
            write(2, "Ambiguous input redirect.\n", 27);
            return (-1);
        }
    }
    return (0);
}

int error_in_pipe(tree_t *ast, object_t *obj)
{
    object_t *left_obj = NULL;

    if (ast->left_tree == NULL || ast->right_tree == NULL) {
        write(2, "Invalid null command.\n", 22);
        return (-1);
    }
    left_obj = ast->left_tree->component;
    if (left_obj != NULL) {
        if (left_obj->type < COMMAND && left_obj->type > SIMPLE_IN) {
            write(2, "Ambiguous input redirect.\n", 27);
            return (-1);
        }
    }
    return (0);
}

int get_error(tree_t *ast, object_t *obj)
{
    int return_value = 0;

    if (obj->type == PIPE) {
        return_value =error_in_pipe(ast, obj);
    }
    if (obj->type == OR && obj->type == AND) {
        return_value = error_in_and_or(ast, obj);
    }
    if (obj->type >= DOUBLE_IN && obj->type <= SIMPLE_OUT) {
        return_value = error_in_redirect(ast, obj);
    }
    return (return_value);
}

int get_ast_error(tree_t *ast)
{
    object_t *obj = NULL;
    int return_value = 0;

    if (ast != NULL) {
        obj = ast->component;
    }
    if (obj != NULL) {
        if (get_error(ast, obj) == -1) {
            return (1);
        }
        if (ast->left_tree != NULL) {
            return_value += get_ast_error(ast->left_tree);
        }
        if (ast->right_tree != NULL) {
            return_value += get_ast_error(ast->right_tree);
        }
    }
    return (return_value);
}
