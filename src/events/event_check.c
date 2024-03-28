/*
** EPITECH PROJECT, 2021
** event_check.c
** File description:
** RPG
*/

#include "header.h"

void event_check(game_t *g)
{
    sfEvent event;

    g->key = 0;
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed)
            get_event_key(event, g);
        g->mouse->x = event.mouseMove.x;
        g->mouse->y = event.mouseMove.y;
        g->mouse->p_x = event.mouseButton.x;
        g->mouse->p_y = event.mouseButton.y;
        if (event.type == sfEvtMouseButtonReleased) {
            g->mouse->r_x = event.mouseButton.x;
            g->mouse->r_y = event.mouseButton.y;
        }
    }
}