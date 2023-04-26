/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** create_tree.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree_t *create_node(char *command)
{
    tree_t *tree = malloc(sizeof(tree_t));

    if (tree) {
        tree->command = command;
        tree->left_tree = NULL;
        tree->right_tree = NULL;
    }
    return (tree);
}

tree_t *add_node(tree_t *left, tree_t *right, char *command)
{
    tree_t *tree = create_node(command);

    if (tree) {
        if (left) {
            tree->left_tree = left;
        }
        if (right) {
            tree->right_tree = right;
        }
    }
    return (tree);
}
