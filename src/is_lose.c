/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** is_lose.c
*/

#include <ncurses.h>
#include "sokoban.h"

static int check_is_blocked(int x, int y)
{
    if ((mvinch(y - 1, x) & A_CHARTEXT) == '#'
        && (mvinch(y, x + 1) & A_CHARTEXT) == '#')
        return (1);
    if ((mvinch(y - 1, x) & A_CHARTEXT) == '#'
        && (mvinch(y, x - 1) & A_CHARTEXT) == '#')
        return (1);
    if ((mvinch(y + 1, x) & A_CHARTEXT) == '#'
        && (mvinch(y, x + 1) & A_CHARTEXT) == '#')
        return (1);
    if ((mvinch(y + 1, x) & A_CHARTEXT) == '#'
        && (mvinch(y, x - 1) & A_CHARTEXT) == '#')
        return (1);
    return (0);
}

int is_lose(object_t *obj)
{
    int i = 0;

    for (; i != obj->nb_box; i += 1) {
        if (check_is_blocked(obj->pos_box[i].x, obj->pos_box[i].y) == 0)
            return (0);
    }
    endwin();
    return (1);
}
