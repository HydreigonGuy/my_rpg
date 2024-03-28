/*
** EPITECH PROJECT, 2021
** add_stats_nums.c
** File description:
** RPG
*/

#include "header.h"

void add_atk_and_hp_num_stats(player_t *plr, number_t *hold)
{
    int x = 520;
    int y = 500;

    for (int i = 1; i <= plr->atk; i = i * 10, hold = hold->next) {
        hold->next = malloc(sizeof(number_t));
        x = x - 10;
        add_one_bag_num(hold->next, x, y, (plr->atk / i) % 10);
    }
    x = 650;
    for (int i = 1; i <= plr->hp; i = i * 10, hold = hold->next) {
        hold->next = malloc(sizeof(number_t));
        x = x - 10;
        add_one_bag_num(hold->next, x, y, (plr->hp / i) % 10);
    }
}

number_t *fill_next_stat_num(player_t *plr)
{
    int x = 350;
    int y = 500;
    number_t *nbr = NULL;
    number_t *hold = NULL;

    nbr = malloc(sizeof(number_t));
    add_one_bag_num(nbr, x, y, plr->level % 10);
    hold = nbr;
    for (int i = 10; i <= plr->level; i = i * 10, hold = hold->next) {
        hold->next = malloc(sizeof(number_t));
        x = x - 10;
        add_one_bag_num(hold->next, x, y, (plr->level / i) % 10);
    }
    add_atk_and_hp_num_stats(plr, hold);
    return (nbr);
}

void add_stats_nums(number_t **nums, player_t *plr)
{
    number_t *hold = *nums;

    if (!*nums) {
        *nums = fill_next_stat_num(plr);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_next_stat_num(plr);
    }
}