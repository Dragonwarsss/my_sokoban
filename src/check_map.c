/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** check_map
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int check_map(char *buff)
{
    int i = 0;
    int store = 0;
    int box = 0;

    for (; buff[i]; i += 1) {
        if (buff[i] != '\n' && buff[i] != '#' && buff[i] != 'X'
            && buff[i] != 'O' && buff[i] != 'P' && buff[i] != ' ') {
            print_err("Invalid map\n");
            return (84);
        }
        if (buff[i] == 'X')
            box += 1;
        else if (buff[i] == 'O')
            store += 1;
    }
    if (box != store) {
        print_err("You need at least the same amount of X and O in the map\n");
        return (84);
    }
    return (0);
}

int check_dir(char *path)
{
    struct stat st;
    int stt = 0;
    int fd = open(path, O_RDONLY);
    char *buffer;
    int status;

    stt = lstat(path, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (!buffer || stt < 0 || fd < 0)
        return (84);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    if (S_ISDIR(st.st_mode)) {
        print_err("Parameter given is invalid.\n");
        return (84);
    }
    close (fd);
    status = check_map(buffer);
    free(buffer);
    return (status);
}
