/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exec_or
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "ast.h"
#include "env.h"

int exec_or(env_t *env, tree_t *ast)
{
    int pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid != 0) {
        waitpid(pid, &wstatus, 0);
        if (!(WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 0)) {
            run_ast(ast->right_tree, env);
        }
    } else {
        run_ast(ast->left_tree, env);
        exit(0);
    }
    clean_ast(ast->left_tree);
    ast->left_tree = NULL;
    clean_ast(ast->right_tree);
    ast->right_tree = NULL;
    return (0);
}

int exec_and(env_t *env, tree_t *ast)
{
    int pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid != 0) {
        waitpid(pid, &wstatus, 0);
        if ((WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 0)) {
            run_ast(ast->right_tree, env);
        }
    } else {
        run_ast(ast->left_tree, env);
        exit(0);
    }
    clean_ast(ast->left_tree);
    ast->left_tree = NULL;
    clean_ast(ast->right_tree);
    ast->right_tree = NULL;
    return (0);
}
