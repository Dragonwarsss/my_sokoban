/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf criterion tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_sokoban, more_O_than_X, .init = redirect_all_std)
{
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    cr_assert(check_map(map) == 84);
}

Test(my_sokoban, count_box)
{
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    cr_assert(count_box(map) == 2);
}

Test(my_sokoban, count_storage)
{
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    cr_assert(count_storage(map) == 1);
}

Test(my_sokoban, get_storage_pos)
{
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    cr_assert(get_storage_pos(map) == 20);
}

Test(my_sokoban, print_usage, .init = redirect_all_std)
{
    print_usage();
    cr_assert_stdout_eq_str("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t"
                            "map file representing the warehouse map, containing ‘#’"
                            " for walls,\n\t"
                            "‘P’ for the player, ‘X’ for boxes and ‘O’"
                            " for storage locations.\n");
}

Test(my_sokoban, count_obj)
{
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    cr_assert(count_obj(map) == 1);
}

Test(my_sokoban, bad_arguments)
{
    char **av = malloc(sizeof(char*) * 3);

    av[0] = malloc(sizeof(char) * 8);
    av[1] = malloc(sizeof(char) * 8);
    av[2] = malloc(sizeof(char) * 8);
    cr_assert(check_args(3, av) == 84);
    free(av[0]);
    free(av[1]);
    free(av[2]);
    free(av);
}

Test(my_sokoban, send_h_flag, .init = redirect_all_std)
{
    char **av = malloc(sizeof(char*) * 2);

    av[0] = my_strdup("./a.out");
    av[1] = my_strdup("-h");
    check_args(2, av);
    cr_assert_stdout_eq_str("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t"
              "map file representing the warehouse map, containing ‘#’"
              " for walls,\n\t"
              "‘P’ for the player, ‘X’ for boxes and ‘O’"
              " for storage locations.\n");
    free(av[0]);
    free(av[1]);
    free(av);
}

Test(my_sokoban, send_h_flag_return_value)
{
    char **av = malloc(sizeof(char*) * 2);

    av[0] = my_strdup("./a.out");
    av[1] = my_strdup("-h");
    cr_assert(check_args(2, av) == 1);
    free(av[0]);
    free(av[1]);
    free(av);
}

Test(my_sokoban, init_object)
{
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    cr_assert(init_object(map)->player.x == 2);
}

Test(my_sokoban, move_box_right)
{
    object_t *obj;
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    obj = init_object(map);
    move_box_right(obj, 2, 2);
    cr_assert(obj->pos_box[0].x == 3);
    free(obj->pos_storage);
    free(obj->pos_box);
    free(obj);
}

Test(my_sokoban, move_box_left)
{
    object_t *obj;
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    obj = init_object(map);
    move_box_left(obj, 2, 2);
    cr_assert(obj->pos_box[0].x == 1);
    free(obj->pos_storage);
    free(obj->pos_box);
    free(obj);
}
Test(my_sokoban, move_box_up)
{
    object_t *obj;
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    obj = init_object(map);
    move_box_up(obj, 2, 2);
    cr_assert(obj->pos_box[0].y == 1);
    free(obj->pos_storage);
    free(obj->pos_box);
    free(obj);
}
Test(my_sokoban, move_box_down)
{
    object_t *obj;
    char *map = "#####\n"
        "# P #\n"
        "# X #\n"
        "# O #\n"
        "# X #\n"
        "#####\n";

    obj = init_object(map);
    move_box_down(obj, 2, 2);
    cr_assert(obj->pos_box[0].y == 3);
    free(obj->pos_storage);
    free(obj->pos_box);
    free(obj);
}
