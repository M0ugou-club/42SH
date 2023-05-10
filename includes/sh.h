/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** 42
*/

#ifndef SH_H_
    #define SH_H_

    #include "env.h"
    #include "tree.h"

    /* Function pointer */
    int exec_or(env_t *env, tree_t *ast);
    int exec_and(env_t *env, tree_t *ast);
    int exec_pipe(env_t *env, tree_t *ast);
    int exec_simple_in(env_t *env, tree_t *ast);
    int exec_double_in(env_t *env, tree_t *ast);
    int exec_command(env_t *env, tree_t *ast);
    int exec_double_out(env_t *env, tree_t *ast);
    int exec_simple_out(env_t *env, tree_t *ast);

    /* Function in function pointer */
    int exec_builtin(env_t *env, char **command_array);
    int exec_intern(env_t *env, char **command_array);
    int error_exec(char **command_array);

    /* Parser */
    int get_next_word_index(char *line);
    char *get_str_from_part(char *line, int middle_index, int index_to_skip,
        char *operator);

#endif /* !SH_H_ */
