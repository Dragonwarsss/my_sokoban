/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** print in error output
*/

#include <unistd.h>

void print_err(char *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    write(2, str, i);
}
