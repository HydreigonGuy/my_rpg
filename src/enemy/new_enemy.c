/*
** EPITECH PROJECT, 2021
** new_enemy.c
** File description:
** RPG
*/

#include "header.h"

enemy_t *new_enemy(void)
{
    enemy_t *enemy = NULL;

    enemy = malloc(sizeof(enemy_t));
    if (rand() % 5 == 2) {
        enemy->spr = fill_sprite("images/goblin.png", 800, 100);
        enemy->atk = 5;
        enemy->hp = 12;
        enemy->type = 1;
    } else {
        enemy->spr = fill_sprite("images/monster.png", 800, 100);
        enemy->atk = 3;
        enemy->hp = 8;
        enemy->type = 0;
    }
    enemy->cooldown = 100;
    fill_rect(enemy->spr, 100, 150);
    enemy->spd = 4;
    enemy->next = NULL;
    return (enemy);
}