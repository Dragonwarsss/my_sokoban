/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** reset game
*/

#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

void reset(game_t *g)
{
    mvprintw(0, 0, g->save);
    set_player_pos(g->obj, g->save);
    free(g->obj->pos_box);
    store_box_location(g->obj, g->save);
}
