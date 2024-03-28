/*
** EPITECH PROJECT, 2021
** settings.c
** File description:
** RPG
*/

#include "header.h"

void settings(game_t *game, int music_num)
{
    button_t **btn = fill_settings_btn();
    sprite_t *bg = fill_sprite("images/start_bg.png", 0, 0);

    mouse_reset(game->mouse);
    game->state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        mouse_check(btn, game, 4);
        change_settings(game, music_num);
        settings_display(btn, bg, game);
    }
    for (int i = 0; i < 1; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    game->state = 0;
}