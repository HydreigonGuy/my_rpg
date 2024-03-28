/*
** EPITECH PROJECT, 2021
** level_up_check.c
** File description:
** RPG
*/

#include "header.h"

void level_up_check(game_t *g)
{
    while (g->player->xp / 10 >= g->player->level) {
        sfSound_play(g->music->sound[1]->sound);
        sfSound_setVolume(g->music->sound[1]->sound, g->music->volume);
        g->player->xp -= g->player->level * 10;
        g->player->level++;
        g->player->max_hp += 2;
        g->player->hp += 2;
    }
}