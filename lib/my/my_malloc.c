/*
** EPITECH PROJECT, 2019
** my_malloc
** File description:
** return
*/

#include <stdlib.h>
#include "my.h"

char *my_malloc(char const *s1, char const *s2)
{
    int len_s1_s2 = 0;
    int i = 0;
    char *result = NULL;

    len_s1_s2 = (my_strlen(s1) + my_strlen(s2) + 1);
    result = malloc(sizeof(char) * len_s1_s2);

    for (; i < len_s1_s2 ; i++)
        result[i] = 0;
    return (result);
}
