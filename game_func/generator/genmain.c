/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "gen.h"
#include "loader.h"

void gen(int h, int w)
{
    int heigth;
    int width;
    FILE *fichier = NULL;
    FILE *maps = NULL;
    dec.map = malloc(sizeof(char) * 5049 + 1);

    fichier = fopen("map.txt", "w");
    heigth = h;
    width = w;
    rush4(heigth, width, fichier);
    fclose(fichier);
    maps = fopen("map.txt", "r");
    fread(dec.map, 5049, 1, fichier);
    fclose(maps);
}