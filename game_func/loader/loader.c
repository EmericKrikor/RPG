/*
** EPITECH PROJECT, 2019
** New Folder
** File description:
** loader.c
*/

#include "loader.h"

text_t load_texture(void)
{
    text_t txt;

    txt.t1t = sfTexture_createFromFile("assets/game/map/wall_mid.png", NULL);
    txt.t2t = sfTexture_createFromFile("assets/game/map/floor_2.png", NULL);
    txt.dod = sfTexture_createFromFile(
    "assets/game/map/doors_leaf_closed.png", NULL);
    return (txt);
}

sp_t set_and_scale(void)
{
    sp_t sps;

    sps.t1 = sfSprite_create();
    sps.t2 = sfSprite_create();
    sps.door = sfSprite_create();
    sfSprite_setTexture(sps.t1, tx.t1t, sfTrue);
    sfSprite_setTexture(sps.t2, tx.t2t, sfTrue);
    sfSprite_setTexture(sps.door, tx.dod, sfTrue);
    sfSprite_scale(sps.t1, (sfVector2f){1.25, 1.4});
    sfSprite_scale(sps.t2, (sfVector2f){1.25, 1.4});
    sfSprite_scale(sps.door, (sfVector2f){0.60, 0.60});
    return sps;
}