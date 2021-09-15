/*
** EPITECH PROJECT, 2020
** load
** File description:
** load
*/

#include "rpg.h"
#include "player.h"
#include "basic.h"

static float loadx[2] =
{
    711,
    700
};

static float loady[2] =
{
    1010,
    1000
};

static const char *load_tx[3] =
{
    "assets/handle/buttons/bar_red.png",
    "assets/handle/buttons/bar.png",
};

load_t load_engine(void)
{
    load.tx = malloc(sizeof(sfTexture*) * 2 + 1);
    load.sp = malloc(sizeof(sfSprite*) * 2 + 1);
    load.texts = malloc(sizeof(sfSprite*) * 1 + 1);

    for (int i = 0; i <= 1; i++) {
        load.tx[i] = sfTexture_createFromFile(load_tx[i], NULL);
        load.sp[i] = sfSprite_create();
        sfSprite_setTexture(load.sp[i], load.tx[i], sfTrue);
        if (i == 0) {
            load.texts[0] = sfText_create();
            sfText_setFont(load.texts[i], font);
        }
    }
    return (load);
}

void load_map(void)
{
    sfRenderWindow_clear(handle_window, sfBlack);
    if (charge <= 100) {
        sfSprite_setScale(load.sp[0], (sfVector2f){charge / 100, 1});
        charge++;
    }
    sfText_setPosition(load.texts[0],
    (sfVector2f){loadx[0]- 50, loady[0] - 50});
    sfText_setString(load.texts[0],
    "You can miss your life but not your death ...");
    sfText_setCharacterSize(load.texts[0], 20);
    sfRenderWindow_drawText(handle_window, load.texts[0], NULL);
    for (int i = 0; i <= 1; i++) {
        sfSprite_setPosition(load.sp[i],
        (sfVector2f){loadx[i], loady[i]});
        sfRenderWindow_drawSprite(handle_window, load.sp[i], NULL);
    }
    sfRenderWindow_display(handle_window);
    if (charge == 101)
        states.game_states = 2;
}