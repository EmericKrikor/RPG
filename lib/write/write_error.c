/*
** EPITECH PROJECT, 2019
** write error
** File description:
** write error for project
*/

#include "basic.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i++; str[i] != '\0'; i++);
    return (i);
}

void write_error(char *s)
{
    write(2, s, my_strlen(s));
}

void write_text(char *s)
{
    write(1, s, my_strlen(s));
}
