/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** run
*/

#include <ncurses.h>
#include "sokoban.h"

int run_game(game_t *g)
{
    initscr();
    curs_set(FALSE);
    noecho();
    keypad(stdscr, TRUE);
    mvprintw(0, 0, g->save);
    while (1) {
        move_player(g);
        mvprintw(g->obj->player.y, g->obj->player.x, "P");
        draw_storage(g->obj->pos_storage, g->obj->nb_storage);
        refresh();
        if (is_win(g->obj->pos_storage, g->obj->nb_storage))
            return (0);
        if (is_lose(g->obj))
            return (1);
    }
    return (0);
}
