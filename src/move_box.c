/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** move_box
*/

#include "sokoban.h"

void move_box_right(object_t *obj, int x, int y)
{
    int i = 0;

    for (; i != obj->nb_box; i += 1)
        if (obj->pos_box[i].x == x && obj->pos_box[i].y == y) {
            obj->pos_box[i].x += 1;
            return;
        }
}

void move_box_left(object_t *obj, int x, int y)
{
    int i = 0;

    for (; i != obj->nb_box; i += 1)
        if (obj->pos_box[i].x == x && obj->pos_box[i].y == y) {
            obj->pos_box[i].x -= 1;
            return;
        }
}

void move_box_up(object_t *obj, int x, int y)
{
    int i = 0;

    for (; i != obj->nb_box; i += 1)
        if (obj->pos_box[i].x == x && obj->pos_box[i].y == y) {
            obj->pos_box[i].y -= 1;
            return;
        }
}

void move_box_down(object_t *obj, int x, int y)
{
    int i = 0;

    for (; i != obj->nb_box; i += 1)
        if (obj->pos_box[i].x == x && obj->pos_box[i].y == y) {
            obj->pos_box[i].y += 1;
            return;
        }
}
