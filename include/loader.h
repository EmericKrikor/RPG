/*
** EPITECH PROJECT, 2019
** New Folder
** File description:
** loader.h
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef LOADER_H
#define LOADER_H

typedef struct dec
{
    char *map;
    int x;
    int y;
}dec_t;

typedef struct sp
{
    sfSprite *t1;
    sfSprite *t2;
    sfSprite *door;
}sp_t;

typedef struct text
{
    sfTexture* t1t;
    sfTexture* t2t;
    sfTexture* dod;
}text_t;

dec_t dec;
sp_t sp;
text_t tx;

sp_t set_and_scale(void);
text_t load_texture(void);
void gen(int x, int y);

#endif