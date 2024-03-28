/*
** EPITECH PROJECT, 2021
** travel_menu_state_set.c
** File description:
** RPG
*/

#include "header.h"

void travel_menu_state_set(game_t *game)
{
    if (game->state == 10)
        game->state = -42;
    if (game->state == 11)
        game->state = -41;
    if (game->state == 12)
        game->state = -40;
    if (game->state == 13)
        game->state = -43;
    if (game->state == 3)
        game->state = 0;
}