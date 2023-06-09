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
    #include "to_free.h"
    #include "unused.h"

    /* Function pointer */
    int exec_or(env_t *env, tree_t *ast, to_free_t *memory_struct);
    int exec_and(env_t *env, tree_t *ast, to_free_t *memory_struct);
    int exec_pipe(env_t *env, tree_t *ast, to_free_t *memory_struct);
    int exec_simple_in(env_t *env, tree_t *ast, to_free_t *memory_struct);
    int exec_double_in(env_t *env, tree_t *ast, to_free_t *memory_struct);
    int exec_command(env_t *env, tree_t *ast, UNUSED to_free_t *memory_struct);
    int exec_double_out(env_t *env, tree_t *ast, to_free_t *memory_struct);
    int exec_simple_out(env_t *env, tree_t *ast, to_free_t *memory_struct);

    /* Function in function pointer */
    int exec_builtin(env_t *env, char **command_array);
    int exec_intern(env_t *env, char **command_array);
    int error_exec(char **command_array);

    /* Parser */
    int get_next_word_index(char *line);
    char *get_str_from_part(char *line, int middle_index, int index_to_skip,
        char *operator);

    /* Functionnnal function*/
    int print_path_prompt(void);
    int run_sh(char *env[]);

#endif /* !SH_H_ */
