/*
** EPITECH PROJECT, 2021
** move_sprite.c
** File description:
** RPG
*/

#include "header.h"

void move_sprite(game_t *g, int scene)
{
    if (g->key == 1) {
        g->player->dir.y -= 75;
        g->player->spr->r.top = 450;
    } if (g->key == 2) {
        g->player->dir.x -= 75;
        g->player->spr->r.top = 150;
    } if (g->key == 3) {
        g->player->dir.x += 75;
        g->player->spr->r.top = 300;
    } if (g->key == 4) {
        g->player->dir.y += 75;
        g->player->spr->r.top = 0;
    }
    player_in_screen(g->player, scene, g->key);
}