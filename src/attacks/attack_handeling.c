/*
** EPITECH PROJECT, 2021
** attack_handeling.c
** File description:
** RPG
*/

#include "header.h"

void refill_lair_cooldowns(lair_t *lair, int delta)
{
    if (lair->punch_cd) {
        lair->punch_cd -= delta;
        if (lair->punch_cd < 0)
            lair->punch_cd = 0;
    }
    if (lair->w_atk_cd) {
        lair->w_atk_cd -= delta;
        if (lair->w_atk_cd < 0)
            lair->w_atk_cd = 0;
    }
}

void attack_handeling_lair(game_t *g, lair_t *lair, int delta)
{
    refill_lair_cooldowns(lair, delta);
    attack_move(lair->atk, delta);
    lair->cooldown -= delta;
    if (lair->cooldown <= 0)
        add_dragon_attack(lair);
    if (g->key == 7 && !lair->punch_cd) {
        add_fist(&lair->atk, g->player);
        lair->punch_cd = 10;
    }
    remove_lair_attacks(lair);
    atk_lair_collision_check(g, lair);
    lair->health_bar->r.left = (50 - lair->hp) * 20;
    sfSprite_setTextureRect(lair->health_bar->spr, lair->health_bar->r);
}

void refill_cave_cooldowns(cave_t *cave, int delta)
{
    if (cave->punch_cd) {
        cave->punch_cd -= delta;
        if (cave->punch_cd < 0)
            cave->punch_cd = 0;
    }
    if (cave->w_atk_cd) {
        cave->w_atk_cd -= delta;
        if (cave->w_atk_cd < 0)
            cave->w_atk_cd = 0;
    }
}

void attack_handeling(game_t *g, cave_t *cave, int delta)
{
    enemy_t *hold = cave->enemy;

    for (; hold; hold = hold->next)
        if (hold->cooldown <= 0) {
            add_enemy_attack(cave, hold, g->player->spr);
            hold->cooldown = 30;
        }
    refill_cave_cooldowns(cave, delta);
    attack_move(cave->atks, delta);
    if (g->key == 7 && !cave->punch_cd) {
        add_fist(&cave->atks, g->player);
        cave->punch_cd = 10;
    }
    if (cave->enemy && cave->atks)
        atk_collision_check(g, cave);
    remove_attacks(cave);
}