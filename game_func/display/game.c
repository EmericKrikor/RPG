/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#include "rpg.h"

void game_player_choose(void)
{
    switch(states.game_states)
    {
        case player_choose:
            player_choose_display();
            break;
        case map_charg:
            load_map();
            break;
        case gmes:
            hud_map();
            break;
        case ps_gme:
            sfRenderWindow_clear(handle_window, sfGreen);
            sfRenderWindow_display(handle_window);
            break;
    }
}