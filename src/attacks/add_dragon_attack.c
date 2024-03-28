/*
** EPITECH PROJECT, 2021
** add_dragon_attack.c
** File description:
** RPG
*/

#include "header.h"

attack_t *create_fireball(sprite_t *spr)
{
    attack_t *hold = NULL;
    int x = spr->crds.x + 150;
    int y = spr->crds.y + 150;

    hold = malloc(sizeof(attack_t));
    hold->spr = fill_sprite("images/fireball.png", x, y);
    fill_rect(hold->spr, 50, 50);
    hold->dir = 1;
    hold->spd = 8;
    hold->damage = 2;
    hold->range = 1000;
    hold->next = NULL;
    hold->allied = 0;
    return (hold);
}

void add_dragon_attack(lair_t *lair)
{
    attack_t *hold = lair->atk;

    if (!lair->atk) {
        lair->atk = create_fireball(lair->dragon);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = create_fireball(lair->dragon);
    }
    lair->cooldown = 30 + rand() % 20;
}