/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** init.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sokoban.h"

char *get_map(char *path)
{
    struct stat st;
    int stt = 0;
    int fd = open(path, O_RDONLY);
    char *buffer;

    stt = stat(path, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (stt < 0 || fd < 0 || !buffer)
        return (NULL);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    close(fd);
    return (buffer);
}

object_t *init_object(char *map)
{
    object_t *tmp = malloc(sizeof(object_t));

    if (!tmp)
        return (NULL);
    set_player_pos(tmp, map);
    store_location(tmp, map);
    store_box_location(tmp, map);
    return (tmp);
}

game_t *init_game(char *path)
{
    game_t *g = malloc(sizeof(game_t));

    if (!g)
        return (NULL);
    g->save = get_map(path);
    g->obj = init_object(g->save);
    if (!g->obj)
        return (NULL);
    return (g);
}
