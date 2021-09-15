/*
** EPITECH PROJECT, 2020
** settings
** File description:
** settings
*/

#include "rpg.h"

long map(long x, long in_min, long in_max)
{
    long out_min = 0;
    long out_max = 100;

    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sound_test(sfVector2i mouse)
{
    float val = 0;

    val = map(mouse.x, 766, 1190);
    if (val / 100 <= 1 || val / 100 >= 0)
        sfSprite_setScale(settings.sp[5], (sfVector2f){val / 100, 1});
}

void music_test(sfVector2i mouse)
{
    float val = 0;

    val = map(mouse.x, 766, 1190);
    if (val / 100 <= 1 || val / 100 >= 0) {
        sfSprite_setScale(settings.sp[4], (sfVector2f){val / 100, 1});
        sfMusic_setVolume(music, val);
    }
}

void test_arrows_sett(int spritepos)
{
    sfVector2i pos;
    sfVector2f sprite;

    pos = sfMouse_getPositionRenderWindow(handle_window);
    sprite = sfSprite_getPosition(settings.sp[spritepos]);
    if (pos.y < sprite.y + 100 && pos.y > sprite.y
    && pos.x < sprite.x + 350 && pos.x > sprite.x) {
        sfSprite_setTexture(settings.sp[spritepos],
        hdl_arrow.tx[spritepos], sfTrue);
        sfRenderWindow_drawSprite(handle_window,
        settings.sp[spritepos], NULL);
    } else {
        sfSprite_setTexture(settings.sp[spritepos],
        settings.tx[spritepos], sfTrue);
        sfRenderWindow_drawSprite(handle_window,
        settings.sp[spritepos], NULL);
    }
}

void musicbar(void)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(handle_window);

    if (mouse.x >= 766 && mouse.x <= 1200) {
        if (mouse.y >= 300 && mouse.y <= 333)
            music_test(mouse);
        if (mouse.y >= 400 && mouse.y <= 433)
            sound_test(mouse);
    }
}