/*
** EPITECH PROJECT, 2021
** cave_interaction_check.c
** File description:
** RPG
*/

#include "header.h"

static void more_interactions(game_t *g, cave_t *cave, int delta)
{
    if (g->state == 3) {
        g->state = 0;
        pause_menu(g, 4);
        sfClock_restart(cave->clock);
    }
    if (g->key == 5) {
        inventory_menu(g, cave->scene->spr[0]);
        sfClock_restart(cave->clock);
        g->time = sfClock_getElapsedTime(g->clock);
    }
    cave_particle_handeling(cave, delta);
    rerect_spr(g->time.microseconds, g->player->spr, 2);
    if (!imobile(g->player))
        walk(g->player, delta);
    move_enemy(g->player->spr, cave->enemy, delta, g->time.microseconds / 30);
    if (g->player->hp <= 0)
        g->state = -4;
    if (rand() % (10) == 1)
        add_particles(&cave->particle, "images/smoke.png", 30);
    moove_hp_bar(g->player, cave->scene->spr[3]);
}

void handle_xp_enemies(player_t *plr, int xp)
{
    plr->xp += xp;
    if (plr->quests[1] < 20 && plr->quests[1] + xp / 5 >= 20)
        plr->gold += 10;
    if (plr->quests[1] < 20)
        plr->quests[1] += xp / 5;
}

void even_more_cave_interactions(game_t *g, cave_t *cave, int delta)
{
    sprite_t *hold = NULL;

    if (g->key == 6 && g->bag->id && !cave->w_atk_cd) {
        add_weapond_atk(g, &cave->atks);
        cave->w_atk_cd = 100;
    }
    hold = cave->scene->spr[4];
    hold->r.left = (cave->w_atk_cd * 40) / 100;
    sfSprite_setTextureRect(hold->spr, hold->r);
    hold = cave->scene->spr[5];
    hold->r.left = (cave->punch_cd * 40) / 10;
    sfSprite_setTextureRect(hold->spr, hold->r);
}

void cave_interaction_check(game_t *g, cave_t *cave, int delta)
{
    int xp = 0;

    if (cave->e_count < 4 && cave_spawn_time(cave)) {
        spawn_enemy(&cave->enemy);
        cave->e_count++;
    } if (g->key == 6)
        if (g->player->spr->crds.x < 400 && g->player->spr->crds.y > 350) {
            travel_menu(g, cave->scene->spr[0]);
            g->time = sfClock_getElapsedTime(g->clock);
            sfClock_restart(cave->clock);
        }
    attack_handeling(g, cave, delta);
    xp = enemies_fainting(g, cave);
    if (xp)
        handle_xp_enemies(g->player, xp);
    level_up_check(g);
    if (g->key && imobile(g->player))
        move_sprite(g, 2);
    more_interactions(g, cave, delta);
    even_more_cave_interactions(g, cave, delta);
}