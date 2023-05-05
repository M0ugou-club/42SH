/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** redirection_execution
*/

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
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

static int exec_out(ast_t *ast, int file_fd, char *file_name)
{
    dup2(file_fd, STDOUT_FILENO);
    run_ast(ast->left);
    dup2(STDOUT_FILENO, file_fd);
    free(file_name);
    close(file_fd);
    free_ast(ast->left);
    free_ast(ast->right);
}

int exec_double_out(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    int file_fd = 0;
    object_t *obj_right = ast->right->component;
    char *file_name = NULL;

    file_name = strclear(obj_right->data);
    if (file_name == NULL)
        return (1);
    file_fd = get_out_file_fd(file_name, 1);
    if (file_fd == -1) {
        free(file_name);
        return (1);
    }
    exec_out(ast, file_fd, file_name);
    return (0);
}

int exec_simple_out(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    int file_fd = 0;
    object_t *obj_right = ast->right->component;
    char *file_name = NULL;

    file_name = strclear(obj_right->data);
    if (file_name == NULL)
        return (1);
    file_fd = get_out_file_fd(file_name, 0);
    if (file_fd == -1) {
        free(file_name);
        return (1);
    }
    exec_out(ast, file_fd, file_name);
    return (0);
}
