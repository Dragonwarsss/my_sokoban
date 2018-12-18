/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** set_player
*/

#include "sokoban.h"

void set_player_pos(object_t *obj, char *map)
{
    int i = 0;
    int y = 0;
    int x = 0;

    for (; map[i] != 'P'; i += 1) {
        if (map[i] == '\n') {
            y += 1;
            x = 0;
        }
        x += 1;
    }
    x -= 1;
    obj->player.x = x;
    obj->player.y = y;
}
