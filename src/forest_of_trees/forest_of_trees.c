/*
** EPITECH PROJECT, 2021
** forest_of_trees.c
** File description:
** RPG
*/

#include "header.h"

static void free_forest_of_trees(forest_t *forest)
{
    for (int i = 0; i < 4; i++)
        free_sprite(forest->forest[i]);
    for (; forest->tree; forest->tree = forest->tree->next)
        free_sprite(forest->tree->spr);
    for (; forest->particle; forest->particle = forest->particle->next)
        free_sprite(forest->particle->spr);
}

void forest_of_trees(game_t *game)
{
    forest_t *forest = forest_fill();
    int delta = 0;

    mouse_reset(game->mouse);
    game->time = sfClock_getElapsedTime(game->clock);
    handle_forest_music(game->music);
    srand(game->time.microseconds % 10000);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        delta = delta_fill(game);
        event_check(game);
        game->player->spr->r.left = 0;
        forest_interaction_check(game, forest, delta);
        forest_display(forest, game);
    }
    sfMusic_stop(game->music->forest_theme);
    if (game->music->is_playing)
        free_forest_of_trees(forest);
}