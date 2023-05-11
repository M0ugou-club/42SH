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
#include "to_free.h"

static void free_pipe(tree_t *ast)
{
    clean_ast(ast->right_tree);
    ast->left_tree = NULL;
    clean_ast(ast->left_tree);
    ast->right_tree = NULL;
}

int exec_child(tree_t *ast, env_t *env, int pfd[2], to_free_t *memory_struct)
{
    int return_value = 0;

    dup2(pfd[1], STDOUT_FILENO);
    if (ast->left_tree != NULL) {
        return_value = run_ast(ast->left_tree, env, memory_struct);
    }
    free_env(env);
    free_all(memory_struct);
    exit(return_value);
    return (return_value);
}

int exec_parent(tree_t *ast, env_t *env, int pfd[2], to_free_t *memory_struct)
{
    int save_in = 0;
    int return_value = 0;

    close(pfd[1]);
    save_in = dup(STDIN_FILENO);
    dup2(pfd[0], STDIN_FILENO);
    if (ast->right_tree != NULL) {
        return_value = run_ast(ast->right_tree, env, memory_struct);
    }
    dup2(save_in, STDIN_FILENO);
    close(pfd[0]);
    return (return_value);
}

int exec_pipe(env_t *env, tree_t *ast, to_free_t *memory_struct)
{
    int pfd[2];
    int pid = 0;
    int wstatus = 0;
    int return_value = -1;

    if (pipe(pfd) < 0)
        return (return_value);
    if ((pid = fork()) == -1)
        return (return_value);
    if (pid != 0) {
        waitpid(pid, &wstatus, 0);
        return_value = exec_parent(ast, env, pfd, memory_struct);
    } else {
        exec_child(ast, env, pfd, memory_struct);
    }
    free_pipe(ast);
    return (return_value);
}
