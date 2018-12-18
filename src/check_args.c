/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** check_args.c
*/

#include "sokoban.h"
#include "my.h"

int check_args(int ac, char **av)
{
    if (ac != 2)
        return (84);
    else if (my_strcomp(av[1], "-h")) {
        print_usage();
        return (1);
    }
    return (check_dir(av[1]));
}
