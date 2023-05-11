/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** main
*/

#include "sh.h"
#include "unused.h"

int main(UNUSED int ac, UNUSED char **av, char *env[])
{
    int return_value = 0;

    return_value = run_sh(env);
    return (return_value);
}
