/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** 42
*/

#ifndef SH_H_
    #define SH_H_

    #include "env.h"
    #include "ast.h"

    /* Function pointer */
    int exec_or(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_and(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_pipe(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_simple_in(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_double_in(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_command(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_double_out(env_t *env, ast_t *ast, int exec_read, int exec_write);
    int exec_simple_out(env_t *env, ast_t *ast, int exec_read, int exec_write);

#endif /* !SH_H_ */
