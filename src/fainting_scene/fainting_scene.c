/*
** EPITECH PROJECT, 2021
** fainting_scene.c
** File description:
** RPG
*/

#include "header.h"

void reset_player(game_t *game)
{
    game->player->max_hp = 10;
    game->player->atk = 3;
    game->player->hp = game->player->max_hp;
    game->player->level = 1;
    game->player->xp = 0;
    game->player->spr->crds.x = 600;
    game->player->spr->crds.y = 400;
    game->player->dir.x = 600;
    game->player->dir.y = 400;
    sfSprite_setPosition(game->player->spr->spr, game->player->spr->crds);
}

void fainting_scene(game_t *game)
{
    sprite_t **spr = fainting_fill();
    int delta = 0;

    game->time = sfClock_getElapsedTime(game->clock);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        delta = delta_fill(game);
        event_check(game);
        map_rerect(delta, spr[0]);
        fainting_display(spr, game);
        if (game->key == 7)
            game->state = -40;
    }
    reset_player(game);
    free_sprite(spr[0]);
    free_sprite(spr[1]);
    free(spr);
}