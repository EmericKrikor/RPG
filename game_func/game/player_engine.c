/*
** EPITECH PROJECT, 2020
** player engine
** File description:
** player engine
*/

#include "basic.h"
#include "player.h"
#include "link_player.h"

void sprite_p(int spritepos)
{
    if (spritepos == 2) {
        states.game_states = 0;
        states.display_states = 0;
        pl.clickk = 0;
        pl.clicke = 0;
        pl.clickw = 0;
    } if (spritepos == 3) {
        pl.clickk = 1;
        pl.clicke = 0;
        pl.clickw = 0;
    } if (spritepos == 4) {
        pl.clickk = 0;
        pl.clicke = 1;
        pl.clickw = 0;
    } if (spritepos == 5) {
        pl.clickk = 0;
        pl.clicke = 0;
        pl.clickw = 1;
    }
}

void setplayerscale(void)
{
    if (pl.clickk == 0)
        sfSprite_setScale(pl.sp[3], (sfVector2f){4, 4});
    else
        sfSprite_setScale(pl.sp[3], (sfVector2f){5, 5});
    if (pl.clicke == 0)
        sfSprite_setScale(pl.sp[4], (sfVector2f){4, 4});
    else
        sfSprite_setScale(pl.sp[4], (sfVector2f){5, 5});
    if (pl.clickw == 0)
        sfSprite_setScale(pl.sp[5], (sfVector2f){4, 4});
    else
        sfSprite_setScale(pl.sp[5], (sfVector2f){5, 5});
}

void test_game(int spritepos)
{
    if (spritepos == 1 &&
    (pl.clickk == 1 || pl.clicke == 1 || pl.clickw == 1)) {
        if (pl.clickk == 1) {
            sfSprite_setScale(pl.sp[3], (sfVector2f){8, 8});
            sfSprite_setPosition(pl.sp[3], (sfVector2f){920, 650});
        } if (pl.clicke == 1) {
            sfSprite_setScale(pl.sp[4], (sfVector2f){8, 8});
            sfSprite_setPosition(pl.sp[4], (sfVector2f){920, 650});

        } if (pl.clickw == 1) {
            sfSprite_setScale(pl.sp[5], (sfVector2f){8, 8});
            sfSprite_setPosition(pl.sp[5], (sfVector2f){920, 650});
        }
        states.game_states = 1;
    }
    sprite_p(spritepos);
}

void test_mouse_game(int spritepos, int x, int x1)
{
    sfVector2i pos;
    sfVector2f sprite;
    sfVector2f txt;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        pos = sfMouse_getPositionRenderWindow(handle_window);
        sprite = sfSprite_getPosition(pl.sp[spritepos]);
        txt = sfText_getPosition(pl.texts[spritepos]);
        if (spritepos < 3) {
            if ((pos.y < sprite.y + x && pos.y > sprite.y)
            && (pos.x < sprite.x + x1 && pos.x > sprite.x))
                test_game(spritepos);
        } else
            if ((pos.y < txt.y + x && pos.y > txt.y)
            && (pos.x < txt.x + x1 && pos.x > txt.x))
                test_game(spritepos);
    }
}

player_choose_t player_engine(void)
{
    pl.tx = malloc(sizeof(sfTexture*) * 6 + 1);
    pl.sp = malloc(sizeof(sfSprite*) * 6 + 1);
    pl.texts = malloc(sizeof(sfText *) * 6 + 1);
    for (int i = 0; i <= 5; i++) {
        pl.tx[i] = sfTexture_createFromFile(playertx[i], NULL);
        pl.sp[i] = sfSprite_create();
        pl.texts[i] = sfText_create();
        sfText_setFont(pl.texts[i], font);
        sfSprite_setTexture(pl.sp[i], pl.tx[i], sfTrue);
    }
    for (int i = 3; i <= 5; i++)
        sfSprite_setOrigin(pl.sp[i], (sfVector2f){8, 28});
    return pl;
}