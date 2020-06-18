/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** return
*/

int my_atoi(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    return (0);
}
