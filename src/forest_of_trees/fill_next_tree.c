/*
** EPITECH PROJECT, 2021
** fill_next_tree.c
** File description:
** RPG
*/

#include "header.h"

tree_t *fill_next_tree(void)
{
    tree_t *tree = NULL;
    sfVector2f scale;
    int y = rand() % 300;

    scale.x = 0.6 + 0.6 * y / 300;
    scale.y = scale.x;
    tree = malloc(sizeof(tree_t));
    tree->spr = fill_sprite("images/tree.png", rand() % 1000, y);
    sfSprite_setScale(tree->spr->spr, scale);
    tree->next = NULL;
    return (tree);
}