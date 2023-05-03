/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** print_tree.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void print_tree(tree_t *tree)
{
    if (tree) {
        if (tree->command)
            puts(tree->command);
        if (tree->left_tree) {
            puts("left son :");
            print_tree(tree->left_tree);
            putchar('\n');
        }
        if (tree->right_tree) {
            puts("right son :");
            print_tree(tree->left_tree);
            putchar('\n');
        }
    }
}
