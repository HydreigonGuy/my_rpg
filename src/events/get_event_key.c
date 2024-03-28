/*
** EPITECH PROJECT, 2021
** get_event_key.c
** File description:
** RPG
*/

#include "header.h"

void get_event_key(sfEvent e, game_t *g)
{
    if (e.key.code == sfKeyEscape)
        g->state = 3;
    if (e.key.code == sfKeyZ || e.key.code == sfKeyUp)
        g->key = 1;
    if (e.key.code == sfKeyQ || e.key.code == sfKeyLeft)
        g->key = 2;
    if (e.key.code == sfKeyD || e.key.code == sfKeyRight)
        g->key = 3;
    if (e.key.code == sfKeyS || e.key.code == sfKeyDown)
        g->key = 4;
    if (e.key.code == sfKeyE)
        g->key = 5;
    if (e.key.code == sfKeyA)
        g->key = 6;
    if (e.key.code == sfKeySpace)
        g->key = 7;
}