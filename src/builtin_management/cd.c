/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** cd
*/

#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "env_utils.h"

static const int BUFFER_SIZE = 512;

static int cd_home(env_t *env, char *old_cwd)
{
    char *home = NULL;

    home = my_getenv(env, "HOME");
    if (!home) {
        write(2, "cd: No home directory.\n", 24);
        return (1);
    }
    build_setenv_command(env, "OLDPWD", old_cwd);
    build_setenv_command(env, "PWD", home);
    if (chdir(home) < 0) {
        return (-1);
    }
    free(home);
    return (0);
}

static int cd_back(env_t *env, char *actual_cwd, char *old_cwd)
{
    char *back = NULL;
    char *pwd = NULL;

    back = my_getenv(env, "OLDPWD");

    if (back == NULL) {
        return -1;
    }
    if (chdir(back) < 0) {
        return -1;
    }
    pwd = getcwd(actual_cwd, 1024);
    if (pwd == NULL)
        return -1;
    build_setenv_command(env, "OLDPWD", old_cwd);
    build_setenv_command(env, "PWD", pwd);
    free(back);
    free(pwd);
    return (0);
}

static int classic_cd(env_t *env, char *actual_cwd, char *old_cwd)
{
    char *pwd = NULL;

    pwd = getcwd(actual_cwd, 1024);
    if (pwd == NULL)
        return -1;
    build_setenv_command(env, "OLDPWD", old_cwd);
    build_setenv_command(env, "PWD", pwd);
    free(pwd);
    return (0);
}

static int manage_cd(env_t *env, char **command_array, char *actual_cwd,
char *old_cwd)
{
    int return_value = 0;

    if (command_array[1] == NULL || strcmp(command_array[1], "~") == 0) {
        return_value = cd_home(env, old_cwd);
        return return_value;
    }
    if (strcmp(command_array[1], "-") == 0) {
        return_value = cd_back(env, actual_cwd, old_cwd);
        return return_value;
    }
    if (is_directory(command_array[1]) == false)
        return 1;
    if (chdir(command_array[1]) < 0)
        return -1;
    classic_cd(env, actual_cwd, old_cwd);
    return (0);
}

int my_cd(env_t *env, char **command_array)
{
    char *actual_cwd = NULL;
    char *old_cwd = NULL;
    int return_value = 0;

    old_cwd = getcwd(old_cwd, BUFFER_SIZE);
    return_value = manage_cd(env, command_array, actual_cwd, old_cwd);
    if (actual_cwd != NULL)
        free(actual_cwd);
    if (old_cwd != NULL)
        free(old_cwd);
    return (return_value);
}
