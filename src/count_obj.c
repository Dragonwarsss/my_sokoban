/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** count_box.c
*/

int count_box(char *map)
{
    int i = 0;
    int nb = 0;

    for (; map[i]; i += 1)
        if (map[i] == 'X')
            nb += 1;
    return (nb);
}

int count_storage(char *map)
{
    int i = 0;
    int nb = 0;

    for (; map[i]; i += 1)
        if (map[i] == 'O')
            nb += 1;
    return (nb);
}

int get_storage_pos(char *map)
{
    static int i = 0;

    while (map[i] != 'O')
        i += 1;
    i += 1;
    return (i - 1);
}
