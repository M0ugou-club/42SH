/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** struct_free_utils
*/

#include <stdlib.h>
#include "ast.h"
#include "tree.h"
#include "env.h"
#include "to_free.h"

void free_all(to_free_t *memory_struct)
{
    if (memory_struct != NULL) {
        if (memory_struct->line != NULL) {
            free(memory_struct->line);
        }
        if (memory_struct->copy != NULL) {
            free(memory_struct->copy);
        }
        if (memory_struct->ast != NULL) {
            clean_ast(memory_struct->ast);
        }
        free(memory_struct);
    }
}

to_free_t *fill_info(tree_t *ast, char *line, char *copy)
{
    to_free_t *memory_struct = NULL;

    memory_struct = malloc(sizeof(to_free_t));
    if (memory_struct != NULL) {
        memory_struct->ast = ast;
        memory_struct->copy = copy;
        memory_struct->line = line;
    }
    return (memory_struct);
}
