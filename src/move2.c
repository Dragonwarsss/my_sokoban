/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** move2.c
*/

#include <ncurses.h>
#include "sokoban.h"

void move_up2(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y - 1, x) & A_CHARTEXT) == 'X'
        && (mvinch(y - 2, x) & A_CHARTEXT) == ' ') {
        g->obj->player.y -= 1;
        mvaddch(y - 1, x, 'P');
        mvaddch(y - 2, x, 'X');
        mvaddch(y, x, ' ');
        move_box_up(g->obj, x, y - 1);
        return;
    }
    if ((mvinch(y - 1, x) & A_CHARTEXT) == 'X'
        && (mvinch(y - 2, x) & A_CHARTEXT) == 'O') {
        g->obj->player.y -= 1;
        mvaddch(y - 1, x, 'P');
        mvaddch(y - 2, x, 'X');
        mvaddch(y, x, ' ');
        move_box_up(g->obj, x, y - 1);
        return;
    }
}

void move_down2(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y + 1 ,x) & A_CHARTEXT) == 'X'
        && (mvinch(y + 2, x) & A_CHARTEXT) == ' ') {
        g->obj->player.y += 1;
        mvaddch(y + 1, x, 'P');
        mvaddch(y + 2, x, 'X');
        mvaddch(y, x, ' ');
        move_box_down(g->obj, x, y + 1);
        return;
    }
    if ((mvinch(y + 1, x) & A_CHARTEXT) == 'X'
        && (mvinch(y + 2, x) & A_CHARTEXT) == 'O') {
        g->obj->player.y += 1;
        mvaddch(y + 1, x, 'P');
        mvaddch(y + 2, x, 'X');
        mvaddch(y, x, ' ');
        move_box_down(g->obj, x, y + 1);
        return;
    }
}

void move_left2(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y, x - 1) & A_CHARTEXT) == 'X'
        && (mvinch(y, x - 2) & A_CHARTEXT) == ' ') {
        g->obj->player.x -= 1;
        mvaddch(y, x - 1, 'P');
        mvaddch(y, x - 2, 'X');
        mvaddch(y, x, ' ');
        move_box_left(g->obj, x - 1, y);
        return;
    }
    if ((mvinch(y, x - 1) & A_CHARTEXT) == 'X'
        && (mvinch(y, x - 2) & A_CHARTEXT) == 'O') {
        g->obj->player.x -= 1;
        mvaddch(y, x - 1, 'P');
        mvaddch(y, x - 2, 'X');
        mvaddch(y, x, ' ');
        move_box_left(g->obj, x - 1, y);
        return;
    }
}

void move_right2(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y, x + 1) & A_CHARTEXT) == 'X'
        && (mvinch(y, x + 2) & A_CHARTEXT) == ' ') {
        g->obj->player.x += 1;
        mvaddch(y, x + 1, 'P');
        mvaddch(y, x + 2, 'X');
        mvaddch(y, x, ' ');
        move_box_right(g->obj, x + 1, y);
        return;
    }
    if ((mvinch(y, x + 1) & A_CHARTEXT) == 'X'
        && (mvinch(y, x + 2) & A_CHARTEXT) == 'O') {
        g->obj->player.x += 1;
        mvaddch(y, x + 1, 'P');
        mvaddch(y, x + 2, 'X');
        mvaddch(y, x, ' ');
        move_box_right(g->obj, x + 1, y);
        return;
    }
}
