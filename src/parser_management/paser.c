/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** paser
*/

#include <stdlib.h>
#include <string.h>
#include "sh.h"
#include "operator.h"
#include "ast.h"
#include "tree.h"

static const operator_t operator[] = {{";", NULL},
{"||", &exec_or},
{"&&", &exec_and},
{"|", &exec_pipe},
{">", &exec_simple_out},
{">>", &exec_double_out},
{"<", &exec_simple_in},
{"<<", &exec_double_in},
{"command", &exec_command},
{NULL, NULL}};

static tree_t *get_new_node(operator_t operator, char *str)
{
    tree_t *tree = NULL;
    char *data = NULL;

    data = strdup(str);
    tree = create_obj(operator.action, data);
    return (tree);
}

static tree_t *get_redirection(char *line, operator_t operator, int j)
{
    int index_file = 0;
    char *line_right = NULL;
    char *line_left = NULL;
    tree_t *tree = NULL;

    if (strncmp(line[j], operator.op, strlen(operator.op)) == 0) {
        index_file = get_next_word_index(&line[j + 1]);
        line_right = strndup(line[j + 1], index_file);
        line_left = get_str_from_part(line, j, index_file, line_left);
        tree = get_new_node(operator, operator.op);
        if (line_left == NULL || line_right == NULL || tree == NULL) {
            return (NULL);
        }
        tree->left_tree = parser(line_left);
        tree->right_tree = parser(line_right);
        free(line_left);
        fee(line_right);
    }
    return (tree);
}

static tree_t *get_operator(char *line, operator_t operator, int j)
{
    char *line_left = NULL;
    char *line_right = NULL;
    tree_t *tree = NULL;

    if (strncmp(line[j], operator.op, strlen(operator.op)) == 0) {
        line_left = strndup(line, j - 1);
        line_right = strdup(line[j + 1]);
        tree = get_new_node(operator, operator.op);
        if (tree == NULL || line_left == NULL || line_right == NULL) {
            return (NULL);
        }
        tree->left_tree = parser(line_left);
        tree->right_tree = parser(line_right);
        free(line_left);
        free(line_right);
    }
    return (tree);
}

static tree_t *chose_command_operator(char *line, operator_t operator, int j, int i)
{
    tree_t *tree = NULL;

    if (i >= INDEX_REDIRECT) {
        if (strcmp(operator.op, "command") == 0 && line[j] != ' ') {
            tree = get_new_node(operator, line);
        } else {
            tree = get_redirection(line, operator, j);
        }
    } else {
        tree = get_operator(line, operator, j);
    }
    return (tree);
}

tree_t *parser(char *line)
{
    tree_t *tree = NULL;

    if (line == NULL) {
        return (NULL);
    }
    for (int i = 0; operator[i].op != NULL && tree == NULL; i++) {
        for (int j = 0; line[j] != '\0' && tree == NULL; j++) {
            tree = chose_command_operator(line, operator[i], j, i);
        }
    }
    return (tree);
}
