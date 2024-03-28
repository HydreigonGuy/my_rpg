/*
** EPITECH PROJECT, 2021
** check_for_dragon_faint.c
** File description:
** RPG
*/

#include "header.h"

void check_for_dragon_faint(lair_t *lair, game_t *g)
{
    if (lair->hp <= 0) {
        free_sprite(lair->dragon);
        lair->dragon = NULL;
        g->player->quests[2] = 1;
        g->player->gold += 100;
        for (; lair->atk; lair->atk = lair->atk->next)
            free_sprite(lair->atk->spr);
        if (g->music->is_playing)
            sfMusic_stop(g->music->lair_theme);
        win_cinematic(g);
        handle_lair_music(g->music);
    }
}