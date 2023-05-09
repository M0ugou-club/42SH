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
#include "env_utils.h"

static const int BUFFER_SIZE = 512;
static const char NO_FILE[29] = ": No such file or directory.\n";
static const char NOT_DIR[19] = ": Not a directory.\n";

static bool is_directory(const char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) != 0) {
        write(2, path, strlen(path));
        write(2, NO_FILE, sizeof(NO_FILE));
        return false;
    }
    if (S_ISDIR(path_stat.st_mode) != 1) {
        write(2, path, strlen(path));
        write(2, NOT_DIR, sizeof(NOT_DIR));
        return false;
    }
    return true;
}

static void cd_home(env_t *env, char *actual_cwd, char *old_cwd)
{
    char *home = NULL;

    home = my_getenv(env, "HOME");
    if (!home) {
        my_putstr_error("cd: No home directory.\n");
        return (env);
    }
    build_setenv_command(env, "OLDPWD", old_cwd);
    build_setenv_command(env, "PWD", home);
    if (chdir(home) < 0) {
        return;
    }
    free(home);
}

static void cd_back(env_t *env, char *actual_cwd, char *old_cwd)
{
    char *back = NULL;

    back = my_getenv(env, "OLDPWD");
    if (back == NULL) {
        return;
    }
    if (chdir(back) < 0) {
        return;
    }
    build_setenv_command(env, "OLDPWD", old_cwd);
    build_setenv_command(env, "PWD", getcwd(actual_cwd, 1024));
    free(back);
}


static int manage_cd(env_t *env, char **command_array, char *actual_cwd,
char *old_cwd)
{
    if (command_array[1] == NULL || strcmp("~", command_array[1])) {
        cd_home(env, actual_cwd, old_cwd);
        return -1;
    }
    if (command_array[1][0]) {
        cd_back(env, actual_cwd, old_cwd);
        return -1;
    }
    if (is_directory(command_array[1]) == false)
        return -1;
    if (chdir(command_array[1]) < 0)
        return -1;
    build_setenv_command(env, "OLDPWD", old_cwd);
    build_setenv_command(env, "PWD", getcwd(actual_cwd, 1024));
    return (0);
}

int cd(env_t *env, char **command_array)
{
    char *actual_cwd = NULL;
    char *old_cwd = NULL;
    int return_value = 0;

    actual_cwd = malloc(sizeof(char) * BUFFER_SIZE);
    old_cwd = malloc(sizeof(char) * BUFFER_SIZE);
    if (actual_cwd == NULL || old_cwd == NULL)
        return;
    old_cwd = getcwd(old_cwd, BUFFER_SIZE);
    return_value =  manage_cd(env, command_array, actual_cwd, old_cwd);
    free(actual_cwd);
    free(old_cwd);
    return (return_value);
}
