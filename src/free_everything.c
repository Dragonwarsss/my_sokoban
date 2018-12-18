/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** free_everything
*/

#include <stdlib.h>
#include "sokoban.h"

void free_everything(game_t *g)
{
    free(g->obj->pos_storage);
    free(g->obj->pos_box);
    free(g->obj);
    free(g->save);
    free(g);
}
