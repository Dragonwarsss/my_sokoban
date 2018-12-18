/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** print_usage.c
*/

#include "my.h"

void print_usage(void)
{
    my_printf("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t"
              "map file representing the warehouse map, containing ‘#’"
              " for walls,\n\t"
              "‘P’ for the player, ‘X’ for boxes and ‘O’"
              " for storage locations.\n");
}
