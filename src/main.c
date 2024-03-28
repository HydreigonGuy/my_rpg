/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** RPG
*/

#include "header.h"

int main(int ac, char **av)
{
    game_t *game = NULL;

    if (check_all_opens())
        return (84);
    if (ac > 2)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (h_case());
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 's' && av[1][2] == '\0')
        return (s_case());
    game = fill_game(ac, av);
    while (game->window && game->state != -3)
        next_scene(game);
    free_game(game);
}