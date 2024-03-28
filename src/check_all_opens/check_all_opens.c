/*
** EPITECH PROJECT, 2021
** check_all_opens.c
** File description:
** RPG
*/

#include "header.h"

int check_next_opens4(void)
{
    if (open_check("music/level_up.wav"))
        return (1);
    if (open_check("music/transaction.wav"))
        return (1);
    if (open_check("music/travel.wav"))
        return (1);
    return (check_even_more_opens());
}

int check_next_opens3(void)
{
    if (open_check("images/misterious_cave.png"))
        return (1);
    if (open_check("images/monster_atk.png"))
        return (1);
    if (open_check("images/monster.png"))
        return (1);
    if (open_check("images/numbers.png"))
        return (1);
    if (open_check("images/play_btn.png"))
        return (1);
    if (open_check("images/player_hp_bar.png"))
        return (1);
    if (open_check("images/player_view.png"))
        return (1);
    if (open_check("images/player.png"))
        return (1);
    if (open_check("images/potion.png"))
        return (1);
    return (check_next_opens4());
}

int check_next_opens2(void)
{
    if (open_check("images/goblin_atk.png"))
        return (1);
    if (open_check("images/goblin.png"))
        return (1);
    if (open_check("images/how_to_play.png"))
        return (1);
    if (open_check("images/hp_bar.png"))
        return (1);
    if (open_check("images/interact.png"))
        return (1);
    if (open_check("images/inventory.png"))
        return (1);
    if (open_check("images/leafs.png"))
        return (1);
    if (open_check("images/leef.png"))
        return (1);
    if (open_check("images/map.png"))
        return (1);
    return (check_next_opens3());
}

int check_next_opens(void)
{
    if (open_check("images/dragon.png"))
        return (1);
    if (open_check("images/exit.png"))
        return (1);
    if (open_check("images/fainted_dragon.png"))
        return (1);
    if (open_check("images/fireball.png"))
        return (1);
    if (open_check("images/fist.png"))
        return (1);
    if (open_check("images/flawwwwless.png"))
        return (1);
    if (open_check("images/Forest_of_trees.png"))
        return (1);
    if (open_check("images/furr.png"))
        return (1);
    if (open_check("images/go_to_city.png"))
        return (1);
    return (check_next_opens2());
}

int check_all_opens(void)
{
    if (open_check("images/apply.png"))
        return (1);
    if (open_check("images/axe_atk.png"))
        return (1);
    if (open_check("images/axe.png"))
        return (1);
    if (open_check("images/back_to_start.png"))
        return (1);
    if (open_check("images/city_bg.png"))
        return (1);
    if (open_check("images/cooldown.png"))
        return (1);
    if (open_check("images/dagger_atk.png"))
        return (1);
    if (open_check("images/dagger.png"))
        return (1);
    if (open_check("images/dragon_lair.png"))
        return (1);
    return (check_next_opens());
}