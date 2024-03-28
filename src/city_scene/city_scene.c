/*
** EPITECH PROJECT, 2021
** city_scene.c
** File description:
** RPG
*/

#include "header.h"

void city_scene(game_t *game)
{
    scene_t *city = city_fill();
    int delta = 0;

    mouse_reset(game->mouse);
    game->time = sfClock_getElapsedTime(game->clock);
    handle_city_music(game->music);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        delta = delta_fill(game);
        event_check(game);
        game->player->spr->r.left = 0;
        city_interaction_check(game, city, delta);
        city_display(city, game);
    }
    for (int i = 0; i < 4; i++)
        free_sprite(city->spr[i]);
    free(city);
    if (game->music->is_playing)
        sfMusic_stop(game->music->city_theme);
}