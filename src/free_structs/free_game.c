/*
** EPITECH PROJECT, 2021
** free_game.c
** File description:
** RPG
*/

#include "header.h"

void free_game(game_t *game)
{
    for (; game->bag; game->bag = game->bag->next)
        if (game->bag->spr)
            free_sprite(game->bag->spr);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    free(game->mouse);
    sfMusic_destroy(game->music->city_theme);
    sfMusic_destroy(game->music->lair_theme);
    sfMusic_destroy(game->music->cave_theme);
    sfMusic_destroy(game->music->forest_theme);
    for (int i = 0; i < 4; i++)
        free_sound(game->music->sound[i]);
    free(game);
}