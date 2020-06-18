/*
** EPITECH PROJECT, 2019
** my_infinadd
** File description:
** return
*/

#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

char *zero(char *str, char *str2)
{
    int k = 0;
    int j = 0;
    int j1 = 0;
    
    for (; str[j] < '1' || str[j] > '9' ; j++) {
        j1++;
        if (str[j] == '\0') {
            free(str);
            free(str2);
            my_putchar('0');
            exit (0);
        }
    }
    while (str[j1] != '\0') {
        str2[k] = str[j1];
        k++;
        j1++;
    }
    return (str2);
}

char *full_operation(char const *s1, char const *s2)
{
    char *result = my_malloc(s1, s2);
    int len_s1 = my_strlen(s1) - 1;
    int len_s2 = my_strlen(s2) - 1;
    int i = 0;
    int nbr1 = 0;
    int nbr2 = 0;
    int detention = 0;
    
    for (i = 0; detention != 0 || len_s1 >= 0
             || len_s2 >= 0 ; i++, len_s1--, len_s2--) {
        nbr1 = (len_s1 >= 0) ? my_atoi(s1[len_s1]) : 0;
        nbr2 = (len_s2 >= 0) ? my_atoi(s2[len_s2]) : 0;
        result[i] = ((nbr1 + nbr2 + detention) % 10) + '0';
        detention = (nbr1 + nbr2 + detention) / 10;
    }
    my_revstr(result);

    return (result);
}

int compare_value(char const *s1, char const *s2)
{
    int j1 = 0;
    int l1 = 0;
    int j2 = 0;
    int l2 = 0;

    for (l1 = 0 ; s1[l1] < '1' || s1[l1] > '9' ; l1++);
    for (l2 = 0 ; s2[l2] < '1' || s2[l2] > '9' ; l2++);
    for (; s1[j1] != '\0' ; j1++);
    j1 = j1 - l1;
    for (; s2[j2] != '\0' ; j2++);
    j2 = j2 - l2;
    if (j1 > j2)
        return (1);
    if (j1 < j2)
        return (2);
    while (j1 == j2) {
        if (s1[l1] > s2[l2])
            return (1);
        if (s1[l1] < s2[l2])
            return (2);
        if (s1[l1] == s2[l2]) {
            l1++;
            l2++;
        }
    }
    return (0);
}

char *sous_more_s1(char const *s1, char const *s2)
{
    char *result = my_malloc(s1, s2);
    int len_s1 = my_strlen(s1) - 1;
    int len_s2 = my_strlen(s2) - 1;
    int i = 0;
    int nbr1 = 0;
    int nbr2 = 0;
    int detention = 0;
    
    for (i = 0 ; detention != 0 || len_s1 >= 0
             || len_s2 >= 0 ; i++, len_s1--, len_s2--) {
        nbr1 = (len_s1 >= 0) ? my_atoi(s1[len_s1]) : 0;
        nbr2 = (len_s2 >= 0) ? my_atoi(s2[len_s2]) : 0;
        nbr2 = (nbr2 + detention);
        if (nbr1 < nbr2)
            nbr1 += 10;
        result[i] = (nbr1 - nbr2) + '0';
        detention = nbr1 / 10;
    }
    my_revstr(result);

    return (result);
        
}

char *sous_more_s2(char const *s1, char const *s2)
{
    char *result = my_malloc(s1, s2);
    int len_s1 = my_strlen(s1) - 1;
    int len_s2 = my_strlen(s2) - 1;
    int i = 0;
    int nbr1 = 0;
    int nbr2 = 0;
    int detention = 0;

    for (i = 0 ; detention != 0 || len_s1 >= 0
             || len_s2 >= 0 ; i++, len_s1--, len_s2--) {
        nbr1 = (len_s1 >= 0) ? my_atoi(s1[len_s1]) : 0;
        nbr2 = (len_s2 >= 0) ? my_atoi(s2[len_s2]) : 0;
        nbr1 = (nbr1 + detention);
        if (nbr2 < nbr1)
            nbr2 += 10;
        result[i] = (nbr2 - nbr1) + '0';
        detention = nbr2 / 10;
    }
    my_revstr(result);

    return (result);
}

char *infinadd(char const *s1, char const *s2)
{
    char *result = NULL;
    char *tab = my_malloc(s1, s2);

    if ((s1[0] == '-' && s2[0] == '-') || (s2[0] != '-' && s1[0] != '-'))
        result = full_operation(s1, s2);
    if (((s1[0] != '-' && s2[0] == '-') || (s1[0] == '-' && s2[0] != '-'))
        && compare_value(s1, s2) == 1)
        result = sous_more_s1(s1, s2);
    if (((s1[0] != '-' && s2[0] == '-') || (s1[0] == '-' && s2[0] != '-'))
        && compare_value(s1, s2) == 2)
        result = sous_more_s2(s1, s2);
    tab = zero(result, tab);
    free(result);
    
    return (tab);
}
