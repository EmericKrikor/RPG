/*
** EPITECH PROJECT, 2020
** ahndle
** File description:
** hanlde
*/

#include "rpg.h"
#include "basic.h"
#include "player.h"

void eventclose(sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(handle_window);
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape)
        && states.display_states == 0)
            sfRenderWindow_close(handle_window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)
        && (states.display_states == 1 || (states.display_states == 2
        && states.game_states == 0)))
            states.display_states = 0;
    }
}

void destroy(void)
{
    free(pl.sp);
    free(pl.tx);
    free(pl.texts);
    free(handle.sp);
    free(handle.tx);
    free(handle.texts);
    free(settings.sp);
    free(settings.tx);
    free(settings.texts);
    sfMusic_destroy(music);
    sfRenderWindow_destroy(handle_window);
}

void switch_display(void)
{
    switch(states.display_states)
    {
        case hdle:
            handle_display();
            break;
        case sett:
            settings_display();
            break;
        case gme:
            game_player_choose();
            break;
    }
}

void event_loop(sfEvent event)
{
    while (sfRenderWindow_pollEvent(handle_window, &event)) {
        eventclose(event);
        if (states.display_states == 0) {
            test_mouse(1, 100, 350);
            test_mouse(2, 100, 350);
            test_mouse(3, 100, 350);
        } if (states.display_states == 1) {
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
                musicbar();
            test_mouse_sett(2, 100, 350);
            test_mouse_sett(3, 100, 350);
            test_mouse_sett(8, 80, 80);
            test_mouse_sett(9, 80, 80);
        } if (states.display_states == 2)
            game_stat(event);
    }
}

void handle_play(void)
{
    sfIntRect rect_knight = {0, 0, 16, 28};

    init_variable();
    while (sfRenderWindow_isOpen(handle_window)) {
        event_loop(event);
        switch_display();
        rect_knight = clock_player(rect_knight, 64);
        rect = rect_knight;
    }
    destroy();
}