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

static void free_pipe(int pfd[2], tree_t *ast)
{
    close(pfd[0]);
    close(pfd[1]);
    clean_ast(ast->right_tree);
    clean_ast(ast->left_tree);
}

int exec_pipe(env_t *env, tree_t *ast)
{
    int pfd[2];
    int pid;
    int wstatus;

    if ((pid = fork()) == -1)
        return (-1);
    if (pipe(pfd) < 0)
        return (-1);
    if (pid == 0) {
        waitpid(pid, &wstatus, 0);
        dup2(pfd[0], STDIN_FILENO);
        wstatus = run_ast(ast->right_tree, env);
        dup2(STDIN_FILENO, pfd[0]);
    } else {
        dup2(pfd[1], STDOUT_FILENO);
        run_ast(ast->left_tree, env);
        exit(0);
    }
    free_pipe(pfd, ast);
    return (wstatus);
}
