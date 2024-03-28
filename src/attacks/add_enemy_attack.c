/*
** EPITECH PROJECT, 2021
** add_enemy_attack.c
** File description:
** RPG
*/

#include "header.h"

int get_abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}

int get_atk_direction(int p_x, int p_y, int e_x, int e_y)
{
    if (p_x > e_x && p_x - e_x > get_abs(p_y - e_y))
        return (2);
    if (p_x < e_x && e_x - p_x > get_abs(p_y - e_y))
        return (1);
    if (p_y > e_y)
        return (0);
    return (3);
}

attack_t *create_enemy_atk(enemy_t *enemy, int p_x, int p_y)
{
    attack_t *ret = NULL;
    int x = enemy->spr->crds.x + 35;
    int y = enemy->spr->crds.y + 60;

    ret = malloc(sizeof(attack_t));
    if (enemy->type == 0)
        ret->spr = fill_sprite("images/monster_atk.png", x, y);
    else
        ret->spr = fill_sprite("images/goblin_atk.png", x, y);
    fill_rect(ret->spr, 30, 30);
    ret->dir = get_atk_direction(p_x, p_y, x, y);
    ret->spd = enemy->spd;
    ret->damage = enemy->atk;
    ret->range = 300;
    ret->next = NULL;
    ret->allied = 0;
    return (ret);
}

void add_enemy_attack(cave_t *cave, enemy_t *enemy, sprite_t *plr)
{
    attack_t *hold = cave->atks;

    if (!cave->atks) {
        cave->atks = create_enemy_atk(enemy, plr->crds.x, plr->crds.y);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = create_enemy_atk(enemy, plr->crds.x, plr->crds.y);
    }
}