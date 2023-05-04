/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** create_obj.c
*/

#include <stdlib.h>
#include "ast.h"
#include "tree.h"

tree_t *create_obj(void (*action) (env_t *env, ast_t *ast, int exec_read, int exec_write), data_type_t enum)
{
    obj_t *obj = NULL;
    tree_t *node = NULL;

    obj = malloc(sizeof(obj_t));
    if (obj) {
        obj->action = action;
        obj->type = enum;
        obj->data = NULL;
        node = create_node(obj);
    }
    return node;
}
