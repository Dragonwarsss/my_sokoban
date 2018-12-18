/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** is_win.c
*/

#include <ncurses.h>
#include "sokoban.h"

int is_win(vector_t *p, int n)
{
    for (int i = 0; i != n; i += 1)
        if ((mvinch(p[i].y, p[i].x) & A_CHARTEXT) != 'X')
            return (0);
    endwin();
    return (1);
}
