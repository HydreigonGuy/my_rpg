/*
** EPITECH PROJECT, 2021
** forest_interaction_check.c
** File description:
** RPG
*/

#include "header.h"

static void forest_interaction_compliment(game_t *g, forest_t *f)
{
    if (g->key == 7 && f->tree)
        chop_tree(g, &f->tree);
    if (rand() % (40) == 1)
        add_tree(&f->tree);
    moove_hp_bar(g->player, f->forest[3]);
    if (rand() % (30) == 1)
        add_particles(&f->particle, "images/leafs.png", 30);
}

void forest_interaction_check(game_t *g, forest_t *f, int delta)
{
    if (g->key == 6)
        if (g->player->spr->crds.x < 400 && g->player->spr->crds.y > 350)
            travel_menu(g, f->forest[0]);
    if (g->key && imobile(g->player))
        move_sprite(g, 3);
    if (g->state == 3) {
        g->state = 0;
        pause_menu(g, 3);
    }
    if (g->key == 5)
        inventory_menu(g, f->forest[0]);
    rerect_spr(g->time.microseconds, g->player->spr, 2);
    if (!imobile(g->player))
        walk(g->player, delta);
    forest_particle_handeling(f, delta);
    forest_interaction_compliment(g, f);
    level_up_check(g);
}