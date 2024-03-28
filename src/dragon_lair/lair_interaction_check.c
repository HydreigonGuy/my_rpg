/*
** EPITECH PROJECT, 2021
** lair_interaction_check.c
** File description:
** RPG
*/

#include "header.h"

static void lair_interaction_compliment2(lair_t *lair)
{
    sprite_t *hold = NULL;

    hold = lair->spr[3];
    hold->r.left = (lair->w_atk_cd * 40) / 100;
    sfSprite_setTextureRect(hold->spr, hold->r);
    hold = lair->spr[4];
    hold->r.left = (lair->punch_cd * 40) / 10;
    sfSprite_setTextureRect(hold->spr, hold->r);
}

static void lair_interaction_compliment(game_t *g, lair_t *lair)
{
    if (g->player->hp <= 0)
        g->state = -4;
    moove_hp_bar(g->player, lair->spr[2]);
    if (g->state == 3) {
        g->state = 0;
        pause_menu(g, 2);
    }
    if (g->key == 6 && g->bag->id && !lair->w_atk_cd) {
        add_weapond_atk(g, &lair->atk);
        lair->w_atk_cd = 100;
    }
    if (g->key == 5) {
        inventory_menu(g, lair->bg);
        g->time = sfClock_getElapsedTime(g->clock);
    }
    lair_interaction_compliment2(lair);
}

void lair_interaction_check(game_t *g, lair_t *lair, int delta)
{
    if (g->key == 6)
        if (g->player->spr->crds.x < 400 && g->player->spr->crds.y > 350)
            travel_menu(g, lair->bg);
    if (g->key && imobile(g->player))
        move_sprite(g, 3);
    rerect_spr(g->time.microseconds, g->player->spr, 2);
    if (lair->dragon) {
        attack_handeling_lair(g, lair, delta);
        rerect_spr(g->time.microseconds, lair->dragon, 3);
        move_dragon(lair, delta);
        check_for_dragon_faint(lair, g);
    }
    if (!imobile(g->player))
        walk(g->player, delta);
    lair_interaction_compliment(g, lair);
}