/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** redirection_in_execution
*/

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include "env.h"
#include "ast.h"

static int exec_in(ast_t *ast, int fd)
{
    dup2(fd, STDOUT_FILENO);
    run_ast(ast->left);
    dup2(STDIN_FILENO, fd);
    free_ast(ast->left);
    free_ast(ast->right);
}

static void free_double_in(int pfd[2], char *stop_str, char *line)
{
    free(stop_str);
    free(line);
    close(pfd[1]);
    close(pfd[0]);
}

int exec_double_in(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    object_t *obj_right = ast->right->component;
    bool end = false;
    char *stop_str = NULL;
    char *line = NULL;
    size_t size = 0;
    int pfd[2];

    if (pipe(pfd) == -1)
        return (-1);
    stop_str = strclear(obj_right->data);
    while ((getline(&line, &size, pfd[0]) != EOF) && end == false) {
        line = replace_char(line, '\n', '\0');
        if (strcnmp(stop_str, line) == 0) {
            end = true;
        } else {
            write(pfd[1], line, strlen(line));
        }
    }
    exec_in(ast, pfd[0]);
    free_double_in(pfd, stop_str, line);
}

int exec_simple_in(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    object_t *obj_right = ast->right->component;
    char *file_name = NULL;
    int file_fd = 0;

    file_name = strclear(obj_right->data);
    if (file_name == NULL) {
        file_fd = open(file_name, O_RDONLY);
    }
    if (file_fd == -1) {
        free(file_name);
        return (-1);
    }
    exec_in(ast, file_fd);
    free(file_name);
    close(file_fd);
    return (0);
}
