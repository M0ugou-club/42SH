/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** to_free
*/

#ifndef TO_FREE_H_
    #define TO_FREE_H_

    #include "tree.h"
    #include "env.h"

    typedef struct to_free_s {
        tree_t *ast;
        char *line;
        char *copy;
    } to_free_t;

    void free_all(to_free_t *memory_struct);
    to_free_t *fill_info(tree_t *ast, char *line, char *copy);

#endif /* !TO_FREE_H_ */
