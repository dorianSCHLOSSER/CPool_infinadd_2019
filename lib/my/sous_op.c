/*
** EPITECH PROJECT, 2019
** sous_op
** File description:
** return
*/

#include <unistd.h>
#include "my.h"

void sous_op(char const *s1, char const *s2)
{
    if ((s1[0] == '-' && s2[0] == '-') || (s1[0] == '-' && (compare_value(s1, s2) == 1))
        || (s2[0] == '-' && (compare_value(s1, s2) == 2)))
        my_putchar('-');
}
