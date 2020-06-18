/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** return
*/
#include <stdio.h>
char *my_revstr(char *str)
{
    char swap;
    int j = 0;
    
    for (; str[j]; j++);

    for (int i = 0 ; i < (j + 1) ; i++) {
        swap = str[i];
        str[i] = str[j - 1];
        str[j - 1] = swap;
        j = j - 1;
        if ( i  == j + 1) {
            swap = str[i];
            str[i] = str[j];
            str[j] = swap;
        }
    }
    return (str);
}

