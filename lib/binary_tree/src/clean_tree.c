/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** clean_tree.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void clean_tree(tree_t *tree)
{
    if (!tree)
        return;
    if (tree->left_tree)
        clean_tree(tree->left_tree);
    if (tree->right_tree)
        clean_tree(tree->right_tree);
    free(tree);
}
