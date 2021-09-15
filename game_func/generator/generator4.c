/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator dante
*/

#include "gen.h"

void test1line4(int x, FILE *fichier, int y, int i)
{
    for (int u = 0; u != x; u++)
        fwrite("-", 1, 1, fichier);
    if (i != y -1)
        fwrite("\n", 1, 1, fichier);
}

void test2line4(int x, int i, FILE *fichier)
{
    for (int u = 0; u != x; u++) {
        if (u == 0 || u == x - 1)
            fwrite("-", 1, 1, fichier);
        if (u > 0 && u < x - 1) {
            if (i % 5 == 0 && u % 10 == 0) {
                if (i % 10 == 0 && u % 10 == 0)
                    fwrite("-", 1, 1, fichier);
                else
                    fwrite("2", 1, 1, fichier);
            } else if (i % 10 == 0 && u % 5 == 0)
                fwrite("2", 1, 1, fichier);
            else if (i % 10 == 0 || u % 10 == 0)
                fwrite("-", 1, 1, fichier);
            else
                fwrite(" ", 1, 1, fichier);
        }
    }
    fwrite("\n", 1, 1, fichier);
}

void testx4(int x, int y, FILE *fichier)
{
    int i = 0;

    while (i != y) {
        if (i == 0 || i == (y - 1)) {
            test1line4(x, fichier, y, i);
            i++;
        } else {
            test2line4(x, i, fichier);
            i++;
        }
    }
}

void rush4(int x, int y, FILE *fichier)
{
    if (x <= 1 || y <= 1) {
        write(2, "Invalid size\n", 13);
    }
    testx4(x, y, fichier);
}
