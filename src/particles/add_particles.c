/*
** EPITECH PROJECT, 2021
** add_particles.c
** File description:
** RPG
*/

#include "header.h"

void add_particles(particle_t **partcl, char *img, int size)
{
    particle_t *hold = *partcl;

    if (!*partcl) {
        *partcl = fill_next_particle(img, size);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_next_particle(img, size);
    }
}