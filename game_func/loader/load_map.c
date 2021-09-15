/*
** EPITECH PROJECT, 2020
** header
** File description:
** header
*/

#include "rpg.h"

void draw_map(char map)
{
    if (map == '2') {
        sfSprite_setPosition(sp.t2, (sfVector2f){dec.x, dec.y});
        sfSprite_setPosition(sp.door, (sfVector2f){dec.x, dec.y + 1});
        sfRenderWindow_drawSprite(handle_window, sp.t2, NULL);
        sfRenderWindow_drawSprite(handle_window, sp.door, NULL);
    }
    if (map == ' ') {
        sfSprite_setPosition(sp.t2, (sfVector2f){dec.x, dec.y});
        sfRenderWindow_drawSprite(handle_window, sp.t2, NULL);
    }
    if (map == '-'){
        sfSprite_setPosition(sp.t1, (sfVector2f){dec.x, dec.y});
        sfRenderWindow_drawSprite(handle_window, sp.t1, NULL);
    }
    dec.x = dec.x + 19;
    if (dec.x > 1920 || map == '\n') {
        dec.x = 0;
        dec.y = dec.y + 22;
    }
}