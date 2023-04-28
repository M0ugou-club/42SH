/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** tree.h
*/
#ifndef TREE_H_
    #define TREE_H_

typedef struct tree_s {
    void *component;
    struct tree_s *right_tree;
    struct tree_s *left_tree;
} tree_t;

tree_t *add_node(tree_t *left, tree_t *right, void *component);
void clean_tree(tree_t *tree);
tree_t *create_node(void *component);
void print_tree(tree_t *tree);

#endif /*TREE_H_*/
