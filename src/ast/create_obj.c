/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** create_obj.c
*/

#include <stdlib.h>
#include "ast.h"
#include "tree.h"
#include "to_free.h"

tree_t *create_obj(int (*action) (env_t *env, tree_t *ast,
    to_free_t *memory_struct), void *data, data_type_t type)
{
    object_t *obj = NULL;
    tree_t *node = NULL;

    obj = malloc(sizeof(object_t));
    if (obj) {
        obj->action = action;
        obj->type = type;
        obj->data = data;
        node = create_node(obj);
    }
    return node;
}
