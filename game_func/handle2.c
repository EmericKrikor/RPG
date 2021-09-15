/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle2.c
*/

#include "rpg.h"
#include "basic.h"
#include "player.h"

void game_stat(sfEvent event)
{
    if (states.game_states == 0) {
        test_mouse_game(1, 100, 350);
        test_mouse_game(2, 100, 350);
        test_mouse_game(3, 30, 90);
        test_mouse_game(4, 30, 50);
        test_mouse_game(5, 30, 100);
    } if (states.game_states == 2) {
        if (pl.clickk == 1)
            check_move(event, 3);
        if (pl.clicke == 1)
            check_move(event, 4);
        if (pl.clickw == 1)
            check_move(event, 5);
    }
}