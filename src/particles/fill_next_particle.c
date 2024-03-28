/*
** EPITECH PROJECT, 2021
** fill_next_particle.c
** File description:
** RPG
*/

#include "header.h"

particle_t *fill_next_particle(char *img, int size)
{
    particle_t *partcl = NULL;

    partcl = malloc(sizeof(particle_t));
    partcl->spr = fill_sprite(img, rand() % 1100, rand() % 150);
    fill_rect(partcl->spr, size, size);
    partcl->spr->r.left = size * (rand() % 3);
    sfSprite_setTextureRect(partcl->spr->spr, partcl->spr->r);
    partcl->next = NULL;
    partcl->spd = rand() % 5 + 2;
    return (partcl);
}