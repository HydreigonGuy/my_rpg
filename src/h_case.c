/*
** EPITECH PROJECT, 2021
** h_case.c
** File description:
** RPG
*/

#include "header.h"

int h_case(void)
{
    write(1, "Welcome to Swag City\n\n", 22);
    write(1, "This is an RPG where you can collect wood and slay", 50);
    write(1, " enemies in order to get items that you can sell for", 52);
    write(1, " gold that you can then trade for weaponds and ", 47);
    write(1, "consumables. Level up to increase your max HP and ", 50);
    write(1, "slay the Evil Dragon to free Swag City and to see ", 50);
    write(1, "a pretty cool end animation!\n\n", 30);
    write(1, "./my_rpg or ./my_rpg player_stats\nWhere player_stats", 52);
    write(1, " is a file with your stats (./my_rpg -s for more info)", 54);
    write(1, "\n\nCheck out the \"how to play\" for more info.\n\n", 46);
    write(1, "Enjoy the game!!!\n", 18);
    return (0);
}