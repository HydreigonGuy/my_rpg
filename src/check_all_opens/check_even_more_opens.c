/*
** EPITECH PROJECT, 2021
** check_even_more_opens.c
** File description:
** RPG
*/

#include "header.h"

int check_even_more_opens5(void)
{
    if (open_check("images/weapond_attack.png"))
        return (1);
    if (open_check("images/wood.png"))
        return (1);
    if (open_check("music/cave_theme.wav"))
        return (1);
    if (open_check("music/city_theme.wav"))
        return (1);
    if (open_check("music/forest_theme.wav"))
        return (1);
    if (open_check("music/lair_theme.wav"))
        return (1);
    if (open_check("music/win.wav"))
        return (1);
    return (0);
}

int check_even_more_opens4(void)
{
    if (open_check("images/tooth.png"))
        return (1);
    if (open_check("images/travel_menu.png"))
        return (1);
    if (open_check("images/tree.png"))
        return (1);
    if (open_check("images/tutorial1.png"))
        return (1);
    if (open_check("images/tutorial2.png"))
        return (1);
    if (open_check("images/use.png"))
        return (1);
    if (open_check("images/victory_scene.png"))
        return (1);
    if (open_check("images/volume_down.png"))
        return (1);
    if (open_check("images/volume_up.png"))
        return (1);
    return (check_even_more_opens5());
}

int check_even_more_opens3(void)
{
    if (open_check("images/shop_btn4.png"))
        return (1);
    if (open_check("images/shop_btn5.png"))
        return (1);
    if (open_check("images/shop_menu.png"))
        return (1);
    if (open_check("images/smoke.png"))
        return (1);
    if (open_check("images/space_to_respawn.png"))
        return (1);
    if (open_check("images/spear_atk.png"))
        return (1);
    if (open_check("images/spear.png"))
        return (1);
    if (open_check("images/start_bg.png"))
        return (1);
    if (open_check("images/toggle_music.png"))
        return (1);
    return (check_even_more_opens4());
}

int check_even_more_opens2(void)
{
    if (open_check("images/scene2.png"))
        return (1);
    if (open_check("images/scene3.png"))
        return (1);
    if (open_check("images/sell_all.png"))
        return (1);
    if (open_check("images/sell_one.png"))
        return (1);
    if (open_check("images/sells.png"))
        return (1);
    if (open_check("images/settings_btn.png"))
        return (1);
    if (open_check("images/shop_btn1.png"))
        return (1);
    if (open_check("images/shop_btn2.png"))
        return (1);
    if (open_check("images/shop_btn3.png"))
        return (1);
    return (check_even_more_opens3());
}

int check_even_more_opens(void)
{
    if (open_check("images/pouch.png"))
        return (1);
    if (open_check("images/punch.png"))
        return (1);
    if (open_check("images/quest1.png"))
        return (1);
    if (open_check("images/quest2.png"))
        return (1);
    if (open_check("images/quest3.png"))
        return (1);
    if (open_check("images/quests_menu.png"))
        return (1);
    if (open_check("images/Resume.png"))
        return (1);
    if (open_check("images/sandwitch.png"))
        return (1);
    if (open_check("images/scene1.png"))
        return (1);
    return (check_even_more_opens2());
}