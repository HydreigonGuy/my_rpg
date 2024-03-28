##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## RPG
##

SRC	=	src/fill_structs/fill_mouse.c	\
		src/fill_structs/fill_game.c	\
		src/fill_structs/fill_sprite.c	\
		src/fill_structs/fill_player.c	\
		src/fill_structs/fill_sound.c	\
		src/fill_structs/fill_bag.c	\
		src/fill_structs/fill_music.c	\
		src/load_file_player/check_if_file_is_valid.c	\
		src/load_file_player/load_file_player.c	\
		src/load_file_player/get_player_stat.c	\
		src/load_file_player/load_quests.c	\
		src/free_structs/free_game.c	\
		src/free_structs/free_sprite.c	\
		src/free_structs/free_sound.c	\
		src/start_menu/fill_start_btn.c	\
		src/start_menu/start_display.c	\
		src/start_menu/start_menu_game_state_set.c	\
		src/start_menu/start_menu.c	\
		src/pause_menu/pause_menu.c	\
		src/pause_menu/pause_menu_display.c	\
		src/pause_menu/fill_pause_btn.c	\
		src/pause_menu/pause_game_state.c	\
		src/settings/settings.c	\
		src/settings/change_settings.c	\
		src/settings/change_volume.c	\
		src/settings/toggle_music.c	\
		src/settings/fill_settings_btn.c	\
		src/settings/settings_display.c	\
		src/quests_menu/quests_menu_display.c	\
		src/quests_menu/fill_quests.c	\
		src/quests_menu/quests_menu.c	\
		src/shop_menu/shop_menu.c	\
		src/shop_menu/shop_menu_display.c	\
		src/shop_menu/purchase_check.c	\
		src/shop_menu/organise_shop_items.c	\
		src/shop_menu/get_sell_item_ig.c	\
		src/shop_menu/sell_item.c	\
		src/shop_menu/fill_shop_scene.c	\
		src/shop_menu/add_gold_nbr.c	\
		src/shop_menu/free_shop_scene.c	\
		src/travel_menu/travel_menu.c	\
		src/travel_menu/trvl_menu_display.c	\
		src/travel_menu/fill_travel_btn.c	\
		src/travel_menu/travel_menu_state_set.c	\
		src/forest_of_trees/forest_of_trees.c	\
		src/forest_of_trees/forest_fill.c	\
		src/forest_of_trees/forest_display.c	\
		src/forest_of_trees/forest_can_interact.c	\
		src/forest_of_trees/forest_interaction_check.c	\
		src/forest_of_trees/add_tree.c	\
		src/forest_of_trees/advance_tree_quest.c	\
		src/forest_of_trees/fill_next_tree.c	\
		src/forest_of_trees/chop_tree.c	\
		src/forest_of_trees/forest_particle_handeling.c	\
		src/forest_of_trees/handle_forest_music.c	\
		src/dragon_lair/lair_fill.c	\
		src/dragon_lair/lair_display.c	\
		src/dragon_lair/move_dragon.c	\
		src/dragon_lair/lair_interaction_check.c	\
		src/dragon_lair/check_for_dragon_faint.c	\
		src/dragon_lair/dragon_lair.c	\
		src/dragon_lair/handle_lair_music.c	\
		src/city_scene/city_scene.c	\
		src/city_scene/city_interaction_check.c	\
		src/city_scene/city_display.c	\
		src/city_scene/city_fill.c	\
		src/city_scene/handle_city_music.c	\
		src/city_scene/city_can_interact.c	\
		src/city_scene/city_menu_picker.c	\
		src/misterious_cave/misterious_cave.c	\
		src/misterious_cave/cave_fill.c	\
		src/misterious_cave/cave_display.c	\
		src/misterious_cave/cave_can_interact.c	\
		src/misterious_cave/handle_cave_music.c	\
		src/misterious_cave/cave_interaction_check.c	\
		src/misterious_cave/free_cave.c	\
		src/misterious_cave/moove_hp_bar.c	\
		src/misterious_cave/cave_spawn_time.c	\
		src/misterious_cave/cave_particle_handeling.c	\
		src/particles/fill_next_particle.c	\
		src/particles/add_particles.c	\
		src/enemy/spawn_enemy.c	\
		src/enemy/new_enemy.c	\
		src/enemy/move_enemy.c	\
		src/enemy/enemies_fainting.c	\
		src/rect_handeling/fill_rect.c	\
		src/rect_handeling/rerect_spr.c	\
		src/mouse/mouse_check.c	\
		src/mouse/mouse_on_button.c	\
		src/mouse/mouse_released_on_button.c	\
		src/mouse/mouse_reset.c	\
		src/events/get_event_key.c	\
		src/events/event_check.c	\
		src/next_scene/next_scene.c	\
		src/walking/move_sprite.c	\
		src/walking/player_in_screen.c	\
		src/walking/city_in_screen.c	\
		src/walking/cave_in_screen.c	\
		src/walking/frst_in_screen.c	\
		src/walking/imobile.c	\
		src/walking/walk.c	\
		src/attacks/add_fist.c	\
		src/attacks/attack_handeling.c	\
		src/attacks/add_weapond_atk.c	\
		src/attacks/attack_move.c	\
		src/attacks/remove_attacks.c	\
		src/attacks/atk_collision_check.c	\
		src/attacks/add_enemy_attack.c	\
		src/attacks/add_dragon_attack.c	\
		src/attacks/atk_lair_collision_check.c	\
		src/fainting_scene/fainting_scene.c	\
		src/fainting_scene/fainting_fill.c	\
		src/fainting_scene/fainting_display.c	\
		src/fainting_scene/map_rerect.c	\
		src/win_cinematic/win_cinematic.c	\
		src/win_cinematic/set_basic_scale.c	\
		src/win_cinematic/move_cinematic_spr.c	\
		src/win_cinematic/fill_cinematic_spr.c	\
		src/win_cinematic/display_cinematic.c	\
		src/level_up/level_up_check.c	\
		src/inventory/add_in_hand_item.c	\
		src/inventory/add_item.c	\
		src/inventory/get_item_spr.c	\
		src/inventory_menu/organise_inventory_items.c	\
		src/inventory_menu/add_bag_nums.c	\
		src/inventory_menu/fill_bag_scene.c	\
		src/inventory_menu/free_bag_scene.c	\
		src/inventory_menu/inventory_display.c	\
		src/inventory_menu/inventory_menu.c	\
		src/inventory_menu/selected_is_usable.c	\
		src/inventory_menu/selected_is_weapond.c	\
		src/inventory_menu/item_select_check.c	\
		src/inventory_menu/use_selected_item.c	\
		src/inventory_menu/add_stats_nums.c	\
		src/inventory_menu/change_in_hand.c	\
		src/how_to_play/fill_toturial.c	\
		src/how_to_play/tuto_menu_display.c	\
		src/how_to_play/how_to_play.c	\
		src/check_all_opens/check_all_opens.c	\
		src/check_all_opens/check_even_more_opens.c	\
		src/check_all_opens/open_check.c	\
		src/delta_fill.c	\
		src/h_case.c	\
		src/s_case.c	\
		src/main.c

NAME = my_rpg

all:
	gcc $(SRC) -o $(NAME) -I include -l csfml-graphics -l csfml-system -l csfml-audio

clean:
	rm -fr *.o

fclean: clean
		rm -fr vg*
		rm -fr $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re