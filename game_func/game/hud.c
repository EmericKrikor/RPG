/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hud
*/

#include "rpg.h"
#include "player.h"
#include "basic.h"
#include "hud.h"

hud_t hud_engine(void)
{
    int x = 3;

    hud.tx = malloc(sizeof(sfTexture*) * 6 + 1);
    hud.sp = malloc(sizeof(sfSprite*) * 6 + 1);
    hud.copy = malloc(sizeof(sfSprite*) * 12 + 1);
    hud.copy_tx = malloc(sizeof(sfTexture*) * 12 + 1);
    for (int i = 0; i <= 5; i++) {
        hud.tx[i] = sfTexture_createFromFile(hud_tx[i], NULL);
        hud.sp[i] = sfSprite_create();
        sfSprite_setTexture(hud.sp[i], hud.tx[i], sfTrue);
    }
    for (int a = 0; a <= 11; a++) {
        if (a == 4 || a == 8)
            x++;
        hud.copy_tx[a] = sfTexture_createFromFile(hud_tx[x], NULL);
        hud.copy[a] = sfSprite_create();
        sfSprite_setTexture(hud.copy[a], hud.copy_tx[a], sfTrue);
    }
    return (hud);
}

void hud_character(void)
{
    sfText* text;
    sfFont* font;

    font = sfFont_createFromFile("assets/fonts/pixelart.ttf");
    text = sfText_create();
    sfText_setString(text, "Beat the final Boss");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 45);
    sfText_setPosition(text, (sfVector2f){5, 1025});
    sfRenderWindow_drawText(handle_window, text, NULL);
    if (pl.clickk == sfTrue) {
        sfSprite_setTextureRect(pl.sp[3], rect);
        sfRenderWindow_drawSprite(handle_window, pl.sp[3], NULL);
    } else if (pl.clicke == sfTrue) {
        sfSprite_setTextureRect(pl.sp[4], rect);
        sfRenderWindow_drawSprite(handle_window, pl.sp[4], NULL);
    } else if (pl.clickw == sfTrue) {
        sfSprite_setTextureRect(pl.sp[5], rect);
        sfRenderWindow_drawSprite(handle_window, pl.sp[5], NULL);
    }
}

void load_next(void)
{
    for (int i = 0; i <= 11; i++) {
        sfSprite_setScale(hud.copy[i],
        (sfVector2f){hud_scale[i], hud_scale[i]});
        sfSprite_setPosition(hud.copy[i],
        (sfVector2f){hud_posx[i], hud_posy[i]});
        sfRenderWindow_drawSprite(handle_window, hud.copy[i], NULL);
    }
}

void hud_map(void)
{
    sfRenderWindow_clear(handle_window, sfBlack);
    sfRenderWindow_setView(handle_window, playerview1);
    for (int i = 0; i != my_strlen(dec.map) + 1; i++)
        draw_map(dec.map[i]);
    dec.x = 0;
    dec.y = 0;
    sfRenderWindow_setView(handle_window, playerview);
    for (int i = 0; i <= 2; i++) {
        sfSprite_setScale(hud.sp[i], (sfVector2f){hud_scale[i], hud_scale[i]});
        sfSprite_setPosition(hud.sp[i],
        (sfVector2f){hudx[i], hudy[i]});
        sfRenderWindow_drawSprite(handle_window, hud.sp[i], NULL);
    }
    load_next();
    hud_character();
    sfRenderWindow_display(handle_window);
}