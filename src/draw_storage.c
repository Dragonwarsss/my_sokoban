/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** draw_storage.c
*/

#include <ncurses.h>
#include "sokoban.h"

void draw_storage(vector_t *pos, int nb_storage)
{
    int k = 0;

    for (; k != nb_storage; k += 1)
        if ((mvinch(pos[k].y, pos[k].x) & A_CHARTEXT) == ' ')
            mvaddch(pos[k].y, pos[k].x, 'O');
}
