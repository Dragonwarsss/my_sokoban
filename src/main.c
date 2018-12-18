/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** main.c
*/

#include <signal.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void force_quit(__attribute__((unused))int sig)
{
    endwin();
    exit(84);
}

int main(int argc, char **argv)
{
    int status = check_args(argc, argv);
    game_t *g;

    signal(SIGINT, force_quit);
    if (status != 0)
        return (status);
    else {
        g = init_game(argv[1]);
        if (!g)
            return (84);
        status = run_game(g);
        free_everything(g);
        return (status);
    }
    return (0);
}
