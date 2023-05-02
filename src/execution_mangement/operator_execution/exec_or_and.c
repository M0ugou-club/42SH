/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_or
*/

#include <sys/wait.h>
#include "ast.h"
#include "env.h"

int exec_or(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    int pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid = 0) {
        waitpid(pid, &wstatus, 0);
        if (!(WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 0)) {
            run_ast(ast->right, env, exec_read, exec_write);
        }
    } else {
        run_ast(ast->left, env, exec_read, exec_write);
        exit(0);
    }
}

int exec_and(env_t *env, ast_t *ast, int exec_read, int exec_write)
{
    int pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid = 0) {
        waitpid(pid, &wstatus, 0);
        if ((WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 0)) {
            run_ast(ast->right, env, exec_read, exec_write);
        }
    } else {
        run_ast(ast->left, env, exec_read, exec_write);
        exit(0);
    }
}
