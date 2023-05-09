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
    int return_value = -1;
    int save_in = 0;

    save_in = dup(STDIN_FILENO);
    dup2(fd, STDIN_FILENO);
    return_value = run_ast(ast->left_tree, env);
    dup2(save_in, STDIN_FILENO);
    clean_ast(ast->left_tree);
    ast->left_tree = NULL;
    clean_ast(ast->right_tree);
    ast->right_tree = NULL;
    return (return_value);
}

static int loop_double_in(char *stop_str, int pfd[2])
{
    bool end = false;
    char *line = NULL;
    size_t size = 0;

    write(1, "> ", 2);
    while (end == false && (getline(&line, &size, stdin) != EOF)) {
        line = replace_char(line, '\n', '\0');
        if (strcmp(stop_str, line) == 0) {
            end = true;
        } else {
            write(pfd[1], line, strlen(line));
            write(pfd[1], "\n", 1);
            write(1, "> ", 2);
        }
    }
    free(line);
    return (0);
}

int exec_double_in(env_t *env, tree_t *ast)
{
    object_t *obj_right = ast->right_tree->component;
    char *stop_str = NULL;
    int pfd[2];
    int return_value = 0;

    if (pipe(pfd) == -1)
        return (-1);
    stop_str = str_clear(obj_right->data);
    loop_double_in(stop_str, pfd);
    close(pfd[1]);
    return_value = exec_in(ast, pfd[0], env);
    free(stop_str);
    close(pfd[0]);
    return (return_value);
}

int exec_simple_in(env_t *env, tree_t *ast)
{
    object_t *obj_right = ast->right_tree->component;
    char *file_name = NULL;
    int file_fd = 0;
    int return_value = 0;

    file_name = str_clear(obj_right->data);
    if (file_name != NULL) {
        file_fd = open(file_name, O_RDONLY);
    }
    if (file_fd == -1) {
        free(file_name);
        return (-1);
    }
    return_value = exec_in(ast, file_fd, env);
    free(file_name);
    close(file_fd);
    return (return_value);
}
