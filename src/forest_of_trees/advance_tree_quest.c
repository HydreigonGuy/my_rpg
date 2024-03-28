/*
** EPITECH PROJECT, 2021
** advance_tree_quest.c
** File description:
** RPG
*/

#include "header.h"

void advance_tree_quest(game_t *g)
{
    g->player->quests[0] = g->player->quests[0] + 1;
    if (g->player->quests[0] == 20)
        g->player->gold += 10;
    if (g->player->quests[0] > 40)
        g->player->quests[0] = 40;
}