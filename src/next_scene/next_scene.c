/*
** EPITECH PROJECT, 2021
** next_scene.c
** File description:
** RPG
*/

#include "header.h"

void more_scenes(game_t *game, int x)
{
    if (x == 4) {
        settings(game, 0);
        game->state = 1;
    }
}

void next_scene(game_t *game)
{
    int x = game->state;
    game->state = 0;

    if (x == 1)
        start_menu(game);
    if (x == -40)
        city_scene(game);
    if (x == -41)
        misterious_cave(game);
    if (x == -42)
        forest_of_trees(game);
    if (x == -43)
        dragon_lair(game);
    if (x == 0)
        game->state = -3;
    if (x == -4)
        fainting_scene(game);
    if (x == -38)
        how_to_play(game);
    more_scenes(game, x);
}