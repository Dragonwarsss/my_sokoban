/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** store_obj_location
*/

#include <stdlib.h>
#include "sokoban.h"

int count_obj(char *map)
{
    int i;
    int nb = 0;

    for (i = 0; map[i]; i += 1)
        if (map[i] == 'O')
            nb += 1;
    return (nb);
}

void store_location(object_t *obj, char *map)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int k = 0;
    int nb_obj = count_obj(map);
    vector_t *pos_obj = malloc(sizeof(vector_t) * nb_obj);

    for (; map[i]; i += 1) {
        if (map[i] == '\n') {
            y += 1;
            x = 0;
        }
        if (map[i] == 'O') {
            pos_obj[k].x = x - 1;
            pos_obj[k].y = y;
            k += 1;
        }
        x += 1;
    }
    obj->nb_storage = nb_obj;
    obj->pos_storage = pos_obj;
}
