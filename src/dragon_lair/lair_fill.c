/*
** EPITECH PROJECT, 2021
** lair_fill.c
** File description:
** RPG
*/

#include "header.h"

void fill_lair_spr(lair_t *ret)
{
    ret->spr = malloc(sizeof(sprite_t *) * 7);
    ret->spr[0] = fill_sprite("images/interact.png", 800, 650);
    ret->spr[1] = fill_sprite("images/player_view.png", 990, 600);
    ret->spr[2] = fill_sprite("images/player_hp_bar.png", 995, 685);
    ret->spr[5] = fill_sprite("images/weapond_attack.png", 1000, 655);
    ret->spr[6] = fill_sprite("images/punch.png", 1050, 655);
    ret->spr[3] = fill_sprite("images/cooldown.png", 1000, 655);
    ret->spr[4] = fill_sprite("images/cooldown.png", 1050, 655);
    fill_rect(ret->spr[3], 40, 20);
    fill_rect(ret->spr[4], 40, 20);
    fill_rect(ret->spr[2], 200, 10);
    ret->punch_cd = 0;
    ret->w_atk_cd = 0;
}

lair_t *lair_fill(int not_spawn_dragon)
{
    lair_t *ret = NULL;

    ret = malloc(sizeof(lair_t));
    ret->bg = fill_sprite("images/scene3.png", 0, 0);
    ret->atk = NULL;
    ret->dragon_moving = 1;
    ret->cooldown = 40;
    if (!not_spawn_dragon) {
        ret->dragon = fill_sprite("images/dragon.png", 920, 0);
        fill_rect(ret->dragon, 300, 300);
        ret->hp = 50;
        ret->health_bar = fill_sprite("images/hp_bar.png", 125, 30);
        fill_rect(ret->health_bar, 1000, 30);
    } else {
        ret->dragon = NULL;
        ret->hp = 0;
    }
    fill_lair_spr(ret);
    return (ret);
}