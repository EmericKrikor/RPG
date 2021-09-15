/*
** EPITECH PROJECT, 2018
** AA Lib
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int i;
    long num = 0;

    for (i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
        num *= 10;
        num += str[i] - 48;
        if (num > 2147483647)
            return (-1);
    }
    return ((int)num);
}
