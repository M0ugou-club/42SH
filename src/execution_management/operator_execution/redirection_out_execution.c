/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** redirection_execution
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ast.h"
#include "env.h"

static int get_out_file_fd(char *file, int clear)
{
    int fd = 0;

    if (clear == 0) {
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    } else {
        fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    }
    return (fd);
}

static int exec_out(tree_t *ast, int file_fd, char *file_name, env_t *env)
{
    dup2(file_fd, STDOUT_FILENO);
    run_ast(ast->left_tree, env);
    dup2(STDOUT_FILENO, file_fd);
    free(file_name);
    close(file_fd);
    clean_ast(ast->left_tree);
    clean_ast(ast->right_tree);
    return (0);
}

int exec_double_out(env_t *env, tree_t *ast)
{
    int file_fd = 0;
    object_t *obj_right = ast->right_tree->component;
    char *file_name = NULL;

    file_name = strclear(obj_right->data);
    if (file_name == NULL)
        return (1);
    file_fd = get_out_file_fd(file_name, 1);
    if (file_fd == -1) {
        free(file_name);
        return (1);
    }
    exec_out(ast, file_fd, file_name, env);
    return (0);
}

int exec_simple_out(env_t *env, tree_t *ast)
{
    int file_fd = 0;
    object_t *obj_right = ast->right_tree->component;
    char *file_name = NULL;

    file_name = strclear(obj_right->data);
    if (file_name == NULL)
        return (1);
    file_fd = get_out_file_fd(file_name, 0);
    if (file_fd == -1) {
        free(file_name);
        return (1);
    }
    exec_out(ast, file_fd, file_name, env);
    return (0);
}
