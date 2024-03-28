/*
** EPITECH PROJECT, 2021
** misterious_cave.c
** File description:
** RPG
*/

#include "header.h"

void misterious_cave(game_t *game)
{
    cave_t *cave = cave_fill();
    enemy_t *enemy = NULL;
    int delta = 0;

    mouse_reset(game->mouse);
    game->time = sfClock_getElapsedTime(game->clock);
    handle_cave_music(game->music);
    srand(game->time.microseconds % 10000);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        delta = delta_fill(game);
        event_check(game);
        game->player->spr->r.left = 0;
        cave_interaction_check(game, cave, delta);
        cave_display(cave, game);
    }
    free_cave(cave);
    if (game->music->is_playing)
        sfMusic_stop(game->music->cave_theme);
}