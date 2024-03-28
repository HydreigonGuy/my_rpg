/*
** EPITECH PROJECT, 2021
** cave_fill.c
** File description:
** RPG
*/

#include "header.h"

void fill_cave_spr(cave_t *ret)
{
    ret->scene->spr[0] = fill_sprite("images/scene1.png", 0, 0);
    ret->scene->spr[1] = fill_sprite("images/interact.png", 800, 650);
    ret->scene->spr[2] = fill_sprite("images/player_view.png", 990, 600);
    ret->scene->spr[3] = fill_sprite("images/player_hp_bar.png", 995, 685);
    ret->scene->spr[6] = fill_sprite("images/weapond_attack.png", 1000, 655);
    ret->scene->spr[7] = fill_sprite("images/punch.png", 1050, 655);
    ret->scene->spr[4] = fill_sprite("images/cooldown.png", 1000, 655);
    ret->scene->spr[5] = fill_sprite("images/cooldown.png", 1050, 655);
    fill_rect(ret->scene->spr[3], 200, 10);
    fill_rect(ret->scene->spr[4], 40, 20);
    fill_rect(ret->scene->spr[5], 40, 20);
}

cave_t *cave_fill(void)
{
    cave_t *ret = NULL;

    ret = malloc(sizeof(cave_t));
    ret->scene = malloc(sizeof(scene_t));
    ret->scene->spr = malloc(sizeof(sprite_t *) * 8);
    fill_cave_spr(ret);
    ret->enemy = NULL;
    ret->e_count = 0;
    ret->clock = sfClock_create();
    ret->particle = NULL;
    ret->atks = NULL;
    ret->punch_cd = 0;
    ret->w_atk_cd = 0;
    return (ret);
}