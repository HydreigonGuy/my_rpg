/*
** EPITECH PROJECT, 2021
** enemies_fainting.c
** File description:
** RPG
*/

#include "header.h"

int check_to_free_enemy(game_t *g, enemy_t *hold, cave_t *cave)
{
    int id = 0;

    if (hold->next->hp <= 0 && hold->next->next) {
        free_sprite(hold->next->spr);
        id = 2 * hold->next->type;
        hold->next = hold->next->next;
        cave->e_count--;
        add_item(g->bag, 23 + id, 1);
        add_item(g->bag, 24 + id, (rand() % 10) / 9);
        return (5);
    } else if (hold->next->hp <= 0) {
        free_sprite(hold->next->spr);
        id = 2 * hold->next->type;
        hold->next = NULL;
        cave->e_count--;
        add_item(g->bag, 23 + id, 1);
        add_item(g->bag, 24 + id, (rand() % 10) / 9);
        return (5);
    }
    return (0);
}

int enemies_fainting(game_t *g, cave_t *cave)
{
    enemy_t *hold = cave->enemy;
    int ret = 0;
    int id = 0;

    if (cave->enemy && cave->enemy->hp <= 0) {
        free_sprite(cave->enemy->spr);
        id = 2 * cave->enemy->type;
        cave->enemy = cave->enemy->next;
        hold = cave->enemy;
        cave->e_count--;
        ret += 5;
        add_item(g->bag, 23 + id, 1);
        add_item(g->bag, 24 + id, (rand() % 10) / 9);
    }
    for (; hold && hold->next; hold = hold->next)
        ret += check_to_free_enemy(g, hold, cave);
    return (ret);
}