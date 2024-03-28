/*
** EPITECH PROJECT, 2021
** city_interaction_check.c
** File description:
** RPG
*/

#include "header.h"

void city_interaction_check(game_t *game, scene_t *city, int delta)
{
    if (game->key == 6)
        city_menu_picker(game, city->spr[0]);
    if (game->key == 5)
        inventory_menu(game, city->spr[0]);
    if (game->key && imobile(game->player))
        move_sprite(game, 1);
    if (game->state == 3) {
        game->state = 0;
        pause_menu(game, 1);
    }
    rerect_spr(game->time.microseconds, game->player->spr, 2);
    if (!imobile(game->player))
        walk(game->player, delta);
    moove_hp_bar(game->player, city->spr[3]);
}