/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int len = 0;
    char *dup = NULL;
    int i = 0;

    if (!src)
        return (NULL);
    len = my_strlen(src);
    dup = malloc(sizeof(char) * len);
    for (i = 0; src[i]; i += 1)
        dup[i] = src[i];
    return (dup);
}
