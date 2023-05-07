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
#include <stdlib.h>
#include <string.h>
#include "env.h"
#include "utils.h"
#include "ast.h"

static int exec_in(tree_t *ast, int fd, env_t *env)
{
    dup2(fd, STDOUT_FILENO);
    run_ast(ast->left_tree, env);
    dup2(STDIN_FILENO, fd);
    clean_ast(ast->left_tree);
    clean_ast(ast->right_tree);
    return (0);
}

static int loop_double_in(char *stop_str, int pfd[2])
{
    bool end = false;
    char *line = NULL;
    size_t size = 0;

    while ((getline(&line, &size, stdin) != EOF) && end == false) {
        line = replace_char(line, '\n', '\0');
        if (strcmp(stop_str, line) == 0) {
            end = true;
        } else {
            write(pfd[1], line, strlen(line));
        }
    }
    free(line);
}

int exec_double_in(env_t *env, tree_t *ast)
{
    object_t *obj_right = ast->right_tree->component;
    char *stop_str = NULL;
    int pfd[2];

    if (pipe(pfd) == -1)
        return (-1);
    stop_str = strclear(obj_right->data);
    loop_double_in(stop_str, pfd);
    exec_in(ast, pfd[0], env);
    free(stop_str);
    close(pfd[1]);
    close(pfd[0]);
    return (0);
}

int exec_simple_in(env_t *env, tree_t *ast)
{
    object_t *obj_right = ast->right_tree->component;
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
    exec_in(ast, file_fd, env);
    free(file_name);
    close(file_fd);
    return (0);
}
