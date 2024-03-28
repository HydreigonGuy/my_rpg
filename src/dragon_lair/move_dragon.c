/*
** EPITECH PROJECT, 2021
** move_dragon.c
** File description:
** RPG
*/

#include "header.h"

void move_dragon(lair_t *lair, int delta)
{
    if (lair->dragon_moving) {
        lair->dragon->crds.y += delta * 3;
    } else {
        lair->dragon->crds.y -= delta * 3;
    }
    if (lair->dragon->crds.y <= 0) {
        lair->dragon->crds.y = 0;
        lair->dragon_moving = 1;
    }
    if (lair->dragon->crds.y >= 400) {
        lair->dragon->crds.y = 400;
        lair->dragon_moving = 0;
    }
    sfSprite_setPosition(lair->dragon->spr, lair->dragon->crds);
}