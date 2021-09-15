/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

static const char *hud_tx[6] =
{
    "assets/game/gui/hud.png",
    "assets/game/gui/pause.png",
    "assets/game/gui/items_bar.png",
    "assets/game/gui/life_1.png",
    "assets/game/gui/speed_1.png",
    "assets/game/gui/magic_1.png"
};

static float hudx[6] =
{
    0,
    1832,
    732,
    0,
    0,
    0
};

static float hudy[6] =
{
    0,
    0,
    1000,
    0,
    0,
    0
};

static float hud_scale[12] =
{
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2
};

static float hud_posx[12] =
{
    170,
    188,
    206,
    224,
    170,
    188,
    206,
    224,
    170,
    188,
    206,
    224
};

static float hud_posy[12] =
{
    12,
    12,
    12,
    12,
    52,
    52,
    52,
    52,
    92,
    92,
    92,
    92
};

#endif /* !HUD_H_ */
