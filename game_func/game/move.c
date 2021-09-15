/*
** EPITECH PROJECT, 2020
** move
** File description:
** move
*/

#include "rpg.h"
#include "player.h"
#include "basic.h"

void check_move(sfEvent event, int spritepos)
{
    if (event.type != sfEvtMouseMoved) {
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfSprite_setScale(pl.sp[spritepos], (sfVector2f){-8, 8});
            sfView_move(playerview1, (sfVector2f) {-1, 0});
        } if (sfKeyboard_isKeyPressed(sfKeyD)) {
            sfSprite_setScale(pl.sp[spritepos], (sfVector2f){8, 8});
            sfView_move(playerview1, (sfVector2f) {1, 0});
        } if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            sfView_move(playerview1, (sfVector2f) {0, -1});
        } if (sfKeyboard_isKeyPressed(sfKeyS)) {
            sfView_move(playerview1, (sfVector2f) {0, 1});
        }
    }
}