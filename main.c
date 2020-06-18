/*
** EPITECH PROJECT, 2019
** main
** File description:
** return
*/

#include <unistd.h>
#include "include/my.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *tab_result = NULL;

    if (argc != 3)
        return (84);
    for (int j = 1 ; argv[1][j] != '\0' ; j++) {
        if ((argv[1][j] < '0' || argv[1][j] > '9')
            && (argv[1][0] != '-' || argv[1][0] == '-'))
            return (84);
    }
    for (int k = 1 ; argv[2][k] != '\0' ; k++) {
        if ((argv[2][k] < '0' || argv[2][k] > '9')
            && (argv[2][0] != '-' || argv[2][0] == '-'))
            return (84);
    }
    
    tab_result = infinadd(argv[1], argv[2]);
    sous_op(argv[1], argv[2]);
    my_putstr(tab_result);
    free(tab_result);

    return (0);
}
