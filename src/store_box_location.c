/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** store_box_location
*/

#include <stdlib.h>
#include <sokoban.h>

void store_box_location(object_t *obj, char *map)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int k = 0;
    int nb_obj = count_box(map);
    vector_t *pos_obj = malloc(sizeof(vector_t) * nb_obj);

    for (; map[i]; i += 1) {
        if (map[i] == '\n') {
            y += 1;
            x = 0;
        }
        if (map[i] == 'X') {
            pos_obj[k].x = x - 1;
            pos_obj[k].y = y;
            k += 1;
        }
        x += 1;
    }
    obj->nb_box = nb_obj;
    obj->pos_box = pos_obj;
}
