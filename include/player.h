/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#ifndef player
#define player

#include "rpg.h"

typedef struct player_choose
{
    sfText **texts;
    sfTexture **tx;
    sfSprite **sp;
    sfBool clickk;
    sfBool clicke;
    sfBool clickw;
}player_choose_t;

player_choose_t pl;

typedef struct load
{
    sfText **texts;
    sfTexture **tx;
    sfSprite **sp;
}load_t;

load_t load;

typedef struct hud
{
    sfTexture **tx;
    sfSprite **sp;
    sfSprite **copy;
    sfTexture **copy_tx;
}hud_t;

hud_t hud;

sfView *playerview;
sfView *playerview1;
sfClock *clock;
sfTime time;

float charge;
player_choose_t player_engine(void);
load_t load_engine(void);
hud_t hud_engine(void);
void setplayerscale(void);
void player_choose_display(void);
void game_stat(sfEvent event);

#endif /* !player */
