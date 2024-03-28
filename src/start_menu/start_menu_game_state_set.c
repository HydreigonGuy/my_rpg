/*
** EPITECH PROJECT, 2021
** start_menu_game_state_set.c
** File description:
** RPG
*/

#include "header.h"

void start_menu_game_state_set(game_t *game)
{
    if (game->state == 10)
        game->state = -40;
    if (game->state == 13)
        game->state = -38;
    if (game->state == 11)
        game->state = 4;
}