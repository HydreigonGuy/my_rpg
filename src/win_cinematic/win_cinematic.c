/*
** EPITECH PROJECT, 2021
** win_cinematic.c
** File description:
** RPG
*/

#include "header.h"

void win_cinematic(game_t *game)
{
    sprite_t **spr = fill_cinematic_spr();
    sfVector2f bg_scale = set_basic_scale();
    float dragon_angle = 0;
    int delta = 0;

    sfSound_play(game->music->sound[0]->sound);
    sfSound_setVolume(game->music->sound[0]->sound, game->music->volume);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        delta = delta_fill(game);
        event_check(game);
        move_cinematic_spr(spr, &bg_scale, &dragon_angle, delta);
        display_cinematic(game, spr);
        if (game->key && game->key < 6)
            game->state = 1;
    }
    game->state = 0;
    for (int i = 0; i < 3; i++)
        free_sprite(spr[i]);
}