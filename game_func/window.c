/*
** EPITECH PROJECT, 2020
** window
** File description:
** window
*/

#include "engine.h"
#include "rpg.h"

sfRenderWindow *create_window(int width, int hight, int pixel)
{
    sfRenderWindow *window;
    sfVideoMode video;

    video.height = hight;
    video.width = width;
    video.bitsPerPixel = pixel;
    video = sfVideoMode_getDesktopMode();
    window = sfRenderWindow_create(video, "MY_RPG",
    sfResize | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void setup_all(void)
{
    load = load_engine();
    hud = hud_engine();
    tx = load_texture();
    sp = set_and_scale();
}

void init_variable(void)
{
    handle_window = create_window(1920, 1080, 64);
    gen(100, 50);
    clock = sfClock_create();
    playerview = sfView_create();
    playerview1 = sfView_create();
    playerview = sfView_createFromRect((sfFloatRect){1920, 1080, 1920, 1080});
    playerview1 = sfView_createFromRect((sfFloatRect){200, 100, 200, 100});
    handle = initengine();
    hdl_arrow = initarrow();
    settings = settengine();
    pl = player_engine();
    setup_all();
    initmusic();
    sfView_setCenter(playerview1, (sfVector2f){100, 60});
    sfView_setViewport(playerview1, (sfFloatRect){0, 0, 1, 1});
    sfView_setViewport(playerview, (sfFloatRect){0, 0, 1, 1});
    sfView_setCenter(playerview, (sfVector2f){960, 540});
    cirbutt = settcircle();
}