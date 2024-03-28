/*
** EPITECH PROJECT, 2021
** chop_tree.c
** File description:
** RPG
*/

#include "header.h"

int can_chop_tree(sprite_t *p, sprite_t *t)
{
    int x = p->crds.x - t->crds.x;
    int y = p->crds.y - t->crds.y;

    if (x < 300 && x > -100)
        if (y < 200 && y > - 100)
            return (1);
    return (0);
}

void free_tree(tree_t *tree)
{
    free_sprite(tree->next->spr);
    if (tree->next->next)
        tree->next = tree->next->next;
    else
        tree->next = NULL;
}

void granting_rewards(game_t *g)
{
    g->player->xp++;
    add_item(g->bag, 21, 2 + (rand() % 4));
    add_item(g->bag, 22, rand() % 3);
}

void chop_tree(game_t *g, tree_t **tree)
{
    tree_t *hold = *tree;

    if (can_chop_tree(g->player->spr, hold->spr)) {
        free_sprite(hold->spr);
        granting_rewards(g);
        *tree = hold->next;
        advance_tree_quest(g);
        return;
    }
    for (; hold && hold->next; hold = hold->next)
        if (can_chop_tree(g->player->spr, hold->next->spr)) {
            granting_rewards(g);
            advance_tree_quest(g);
            free_tree(hold);
            return;
        }
}