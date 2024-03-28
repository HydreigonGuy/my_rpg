/*
** EPITECH PROJECT, 2021
** fill_game.c
** File description:
** RPG
*/

#include "header.h"

char *get_save_file(int ac, char **av)
{
    char *hold = NULL;
    int len = 0;

    if (ac == 2) {
        for (; av[1][len]; len++);
        hold = malloc(sizeof(char) * (len + 1));
        for (int i = 0; av[1][i]; i++)
            hold[i] = av[1][i];
        hold[len] = '\0';
        return (hold);
    } else
        return ("save_file.txt\0");
}

game_t *fill_game(int ac, char **av)
{
    game_t *g;
    sfVideoMode m = {1200, 700, 32};
    char wn[] = "RPG";

    g = malloc(sizeof(game_t));
    g->window = sfRenderWindow_create(m, wn, sfResize | sfClose, NULL);
    g->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(g->window, 30);
    g->state = 1;
    g->mouse = fill_mouse();
    g->player = fill_player(ac, av);
    g->save_file = get_save_file(ac, av);
    g->bag = fill_bag();
    g->music = fill_music();
    return (g);
}