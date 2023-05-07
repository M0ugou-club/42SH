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
    if (!tree)
        return;
    if (tree->left_tree)
        clean_tree(tree->left_tree);
    if (tree->right_tree)
        clean_tree(tree->right_tree);
    if (tree->component) {
        free_obj(tree->component);
        free(tree->component);
    }
    free(tree);
}
