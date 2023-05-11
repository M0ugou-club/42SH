/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** error_cd
*/

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

static const char NO_FILE[29] = ": No such file or directory.\n";
static const char NOT_DIR[19] = ": Not a directory.\n";

bool is_directory(const char *path)
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
