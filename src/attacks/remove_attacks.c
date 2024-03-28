/*
** EPITECH PROJECT, 2021
** remove_attacks.c
** File description:
** RPG
*/

#include "header.h"

void remove_lair_attacks(lair_t *l)
{
    attack_t *hold = l->atk;

    if (l->atk && l->atk->range < 0) {
        free_sprite(l->atk->spr);
        l->atk = l->atk->next;
        hold = l->atk;
    }
    for (; hold && hold->next; hold = hold->next) {
        if (hold->next->range < 0 && hold->next->next) {
            free_sprite(hold->next->spr);
            hold->next = hold->next->next;
        } else if (hold->next->range < 0) {
            free_sprite(hold->next->spr);
            hold->next = NULL;
        }
    }
}

void remove_attacks(cave_t *c)
{
    attack_t *hold = c->atks;

    if (c->atks && c->atks->range < 0) {
        free_sprite(c->atks->spr);
        c->atks = c->atks->next;
        hold = c->atks;
    }
    for (; hold && hold->next; hold = hold->next) {
        if (hold->next->range < 0 && hold->next->next) {
            free_sprite(hold->next->spr);
            hold->next = hold->next->next;
        } else if (hold->next->range < 0) {
            free_sprite(hold->next->spr);
            hold->next = NULL;
        }
    }
}