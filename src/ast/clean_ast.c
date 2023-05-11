/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** clean_ast.c
*/

#include <stdlib.h>
#include "tree.h"
#include "ast.h"

static void free_obj(object_t *obj)
{
    if (obj->data)
        free(obj->data);
}

void clean_ast(tree_t *tree)
{
    if (tree == NULL)
        return;
    if (tree->left_tree != NULL)
        clean_ast(tree->left_tree);
    if (tree->right_tree != NULL)
        clean_ast(tree->right_tree);
    if (tree->component != NULL) {
        free_obj(tree->component);
        free(tree->component);
    }
    free(tree);
}
