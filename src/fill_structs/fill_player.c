/*
** EPITECH PROJECT, 2021
** fill_player.c
** File description:
** RPG
*/

#include "header.h"

int *fill_empty_quests(void)
{
    int *quests = NULL;

    quests = malloc(sizeof(int) * 3);
    quests[0] = 0;
    quests[1] = 0;
    quests[2] = 0;
    return (quests);
}

player_t *new_player(void)
{
    player_t *ret = NULL;

    ret = malloc(sizeof(player_t));
    ret->gold = 0;
    ret->hp = 10;
    ret->max_hp = 10;
    ret->atk = 3;
    ret->spd = 12;
    ret->spr = fill_sprite("images/player.png", 500, 300);
    fill_rect(ret->spr, 100, 150);
    ret->dir.x = 500;
    ret->dir.y = 300;
    ret->level = 1;
    ret->xp = 0;
    ret->quests = fill_empty_quests();
    return (ret);
}

player_t *fill_player(int ac, char **av)
{
    player_t *ret = NULL;

    if (ac == 2) {
        ret = load_file_player(av[1]);
        if (!ret) {
            write(2, "Could not load player stats from file\n", 38);
            ret = new_player();
        }
    } else
        ret = new_player();
    return (ret);
}