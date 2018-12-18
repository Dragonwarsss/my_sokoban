/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** move.c
*/

#include <ncurses.h>
#include "sokoban.h"

void move_player(game_t *g)
{
    switch (getch()) {
    case KEY_UP:
        move_up(g);
        break;
    case KEY_DOWN:
        move_down(g);
        break;
    case KEY_LEFT:
        move_left(g);
        break;
    case KEY_RIGHT:
        move_right(g);
        break;
    case ' ':
        reset(g);
        break;
    }
}

void move_up(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y - 1, x) & A_CHARTEXT) == ' '
        || (mvinch(y - 1, x) & A_CHARTEXT) == 'O') {
        g->obj->player.y -= 1;
        mvaddch(y - 1, x, 'P');
        mvaddch(y, x, ' ');
        return;
    }
    move_up2(g);
}

void move_down(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y + 1, x) & A_CHARTEXT) == ' '
        || (mvinch(y + 1, x) & A_CHARTEXT) == 'O') {
        g->obj->player.y += 1;
        mvaddch(y + 1, x, 'P');
        mvaddch(y, x, ' ');
        return;
    }
    move_down2(g);
}

void move_left(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y, x - 1) & A_CHARTEXT) == ' '
        || (mvinch(y, x - 1) & A_CHARTEXT) == 'O') {
        g->obj->player.x -= 1;
        mvaddch(y, x - 1, 'P');
        mvaddch(y, x, ' ');
        return;
    }
    move_left2(g);
}

void move_right(game_t *g)
{
    int x = g->obj->player.x;
    int y = g->obj->player.y;

    if ((mvinch(y, x + 1) & A_CHARTEXT) == ' '
        || (mvinch(y, x + 1) & A_CHARTEXT) == 'O') {
        g->obj->player.x += 1;
        mvaddch(y, x + 1, 'P');
        mvaddch(y, x, ' ');
        return;
    }
    move_right2(g);
}
