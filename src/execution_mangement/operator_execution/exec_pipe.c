/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_pipe
*/

#include <sys/wait.h>
#include <unistd.h>
#include "ast.h"

int exec_pipe(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    int pfd[2];
    int pid;
    int wstatus;

    if (pipe(pfd) < 0)
        return (-1);
    if ((pid = fork()) == -1)
        return (-1);
    dup2(exec_read, STDIN_FILENO);
    if (pid == 0) {
        waitpid(pid, &wstatus, 0);
        wstatus = run_ast(ast->right, env, pfd[0], exec_write);
    } else {
        dup2(pfd[1], STDOUT_FILENO);
        run_ast(ast->left, env, exec_read, pfd[1]);
        exit(0);
    }
    free_ast(ast->right);
    free_ast(ast->left);
    return (wstatus);
}
