/*
** EPITECH PROJECT, 2021
** dragon_lair.c
** File description:
** RPG
*/

#include "header.h"

static void free_lair(lair_t *lair)
{
    free_sprite(lair->bg);
    if (lair->dragon) {
        free_sprite(lair->dragon);
        free_sprite(lair->health_bar);
    }
    for (; lair->atk; lair->atk = lair->atk->next)
        free_sprite(lair->atk->spr);
    for (int i = 0; i < 7; i++)
        free_sprite(lair->spr[i]);
}

void dragon_lair(game_t *game)
{
    lair_t *lair = lair_fill(game->player->quests[2]);
    int delta = 0;

    mouse_reset(game->mouse);
    handle_lair_music(game->music);
    game->time = sfClock_getElapsedTime(game->clock);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        delta = delta_fill(game);
        event_check(game);
        game->player->spr->r.left = 0;
        lair_interaction_check(game, lair, delta);
        lair_display(lair, game);
    }
    free_lair(lair);
    if (game->music->is_playing)
        sfMusic_stop(game->music->lair_theme);
}