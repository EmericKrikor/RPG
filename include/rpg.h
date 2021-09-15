/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** rpg
*/

#ifndef rpg
#define rpg

#include "engine.h"
#include "player.h"
#include "loader.h"
#include "gen.h"


void game_player_choose(void);
int my_strlen(char *str);
void draw_map(char map);
sfRenderWindow *create_window(int width, int hight, int pixel);
sfRenderWindow *handle_window;
handle_t initengine(void);
handle_arrow_t initarrow(void);
settings_butt_t settcircle(void);
settings_t settengine(void);
sfIntRect clock_player(sfIntRect rect_player, int size);
void init_variable(void);
void initmusic(void);
void settings_display(void);
void musicbar(void);
void load_map(void);
void test_arrows(int spritepos);
void test_mouse_game(int spritepos, int x, int x1);
void test_mouse(int spritepos, int x, int x1);
void test_mouse_sett(int spritepos, int x, int x1);
void test_arrows_sett(int spritepos);
void handle_display(void);
void check_move(sfEvent event, int spritepos);
void hud_map(void);

#endif /* !rpg */
