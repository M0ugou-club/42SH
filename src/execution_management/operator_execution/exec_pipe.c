/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_pipe
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "ast.h"

static void free_pipe(tree_t *ast)
{
    clean_ast(ast->right_tree);
    ast->left_tree = NULL;
    clean_ast(ast->left_tree);
    ast->right_tree = NULL;
}

int exec_child(tree_t *ast, env_t *env, int pfd[2])
{
    int return_value = 0;

    dup2(pfd[1], STDOUT_FILENO);
    return_value = run_ast(ast->left_tree, env);
    exit(return_value);
    return (return_value);
}

int exec_parent(tree_t *ast, env_t *env, int pfd[2])
{
    int save_in = 0;
    int return_value = 0;

    close(pfd[1]);
    save_in = dup(STDIN_FILENO);
    dup2(pfd[0], STDIN_FILENO);
    return_value = run_ast(ast->right_tree, env);
    dup2(save_in, STDIN_FILENO);
    close(pfd[0]);
    return (return_value);
}

int exec_pipe(env_t *env, tree_t *ast)
{
    int pfd[2];
    int pid = 0;
    int wstatus = 0;
    int return_value = -1;

    if ((pid = fork()) == -1)
        return (return_value);
    if (pipe(pfd) < 0)
        return (return_value);
    if (pid != 0) {
        waitpid(pid, &wstatus, 0);
        return_value = exec_parent(ast, env, pfd);
    } else {
        exec_child(ast, env, pfd);
    }
    free_pipe(ast);
    return (return_value);
}
