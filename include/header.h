/*
** EPITECH PROJECT, 2021
** header.h
** File description:
** RPG
*/

#ifndef HEADER
#define HEADER

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct sprite_s {
    sfTexture *txtr;
    sfSprite *spr;
    sfIntRect r;
    sfVector2f crds;
} sprite_t;

typedef struct button_s {
    sprite_t *spr;
    int state;
} button_t;

typedef struct enemy_s {
    sprite_t *spr;
    int spd;
    int atk;
    int hp;
    int type;
    int cooldown;
    struct enemy_s *next;
} enemy_t;

typedef struct {
    int x;
    int y;
    int p_x;
    int p_y;
    int r_x;
    int r_y;
} mouse_t;

typedef struct bag_s {
    int id;
    int quantity;
    sprite_t *spr;
    struct bag_s *next;
} bag_t;

typedef struct player_s {
    sprite_t *spr;
    sfVector2f dir;
    int *quests;
    int gold;
    int hp;
    int max_hp;
    int atk;
    int spd;
    int level;
    int xp;
} player_t;

typedef struct scene_s {
    button_t **btn;
    sprite_t **spr;
} scene_t;

typedef struct number_s {
    sprite_t *spr;
    struct number_s *next;
} number_t;

typedef struct bag_scene_s {
    number_t *nbr;
    sprite_t *board;
    button_t **btn;
    int select;
    int display_use;
} bag_scene_t;

typedef struct attack_s {
    sprite_t *spr;
    int allied;
    int damage;
    int range;
    int spd;
    int dir;
    struct attack_s *next;
} attack_t;

typedef struct tree_s {
    sprite_t *spr;
    struct tree_s *next;
} tree_t;

typedef struct particle_s {
    sprite_t *spr;
    int spd;
    struct particle_s *next;
} particle_t;

typedef struct cave_s {
    scene_t *scene;
    enemy_t *enemy;
    attack_t *atks;
    particle_t *particle;
    sfClock *clock;
    int e_count;
    int punch_cd;
    int w_atk_cd;
} cave_t;

typedef struct forest_s {
    sprite_t **forest;
    tree_t *tree;
    particle_t *particle;
} forest_t;

typedef struct lair_s {
    sprite_t *bg;
    sprite_t *dragon;
    sprite_t *health_bar;
    attack_t *atk;
    sprite_t **spr;
    int dragon_moving;
    int hp;
    int cooldown;
    int punch_cd;
    int w_atk_cd;
} lair_t;

typedef struct sound_s {
    sfSoundBuffer *buff;
    sfSound *sound;
} sound_t;

typedef struct music_s {
    sfMusic *city_theme;
    sfMusic *lair_theme;
    sfMusic *forest_theme;
    sfMusic *cave_theme;
    sound_t **sound;
    int volume;
    int is_playing;
} music_t;

typedef struct game_s {
    mouse_t *mouse;
    player_t *player;
    bag_t *bag;
    music_t *music;
    sfRenderWindow *window;
    sfClock *clock;
    sound_t **sounds;
    sfTime time;
    char *save_file;
    int state;
    int key;
} game_t;

// fill_structs
game_t *fill_game(int ac, char **av);
mouse_t *fill_mouse(void);
sprite_t *fill_sprite(char *file, int setx, int sety);
player_t *fill_player(int ac, char **av);
bag_t *fill_bag(void);
music_t *fill_music(void);
sound_t *fill_sound(char *file);

// load_file_player
player_t *load_file_player(char *file);
int get_player_stat(char *stats, int stat_num);
int *load_quests(char *stats);
int check_if_file_is_valid(char *str);

// free_structs
void free_game(game_t *game);
void free_sprite(sprite_t *spr);
void free_sound(sound_t *sound);

// rect_handeling
void fill_rect(sprite_t *spr, int x, int y);
void rerect_spr(int t, sprite_t *spr, int c);

// next_scene
void next_scene(game_t *game);

// events
void event_check(game_t *g);
void get_event_key(sfEvent e, game_t *g);

// mouse
void mouse_reset(mouse_t *mouse);
int mouse_released_on_button(mouse_t *m, button_t *btn);
int mouse_pressed_button(mouse_t *m, button_t *btn);
int mouse_on_button(mouse_t *m, button_t *btn);
void mouse_check(button_t **btn, game_t *game, int c);

// start_menu
void start_menu(game_t *game);
button_t **fill_start_btn(void);
void start_display(sprite_t *bg, button_t **btn, game_t *g);
void start_menu_game_state_set(game_t *game);

// city_scene
void city_scene(game_t *game);
scene_t *city_fill(void);
void city_display(scene_t *s, game_t *g);
void city_interaction_check(game_t *game, scene_t *city, int dalta);
int city_can_interact(sprite_t *spr);
void city_menu_picker(game_t *g, sprite_t *spr);
void handle_city_music(music_t *music);

// quests_menu
void quests_menu(game_t *game, sprite_t *bg);
void qst_mnu_display(button_t **btn, sprite_t *bg, sprite_t *brd, game_t *g);
button_t **fill_quests(void);

// shop_menu
void shop_menu(game_t *game, sprite_t *bg);
void shop_menu_display(scene_t *shop, sprite_t *bg, game_t *g, number_t *qtts);
void free_shop_scene(scene_t *shop);
scene_t *fill_shop_scene(void);
void purchase_check(game_t *g);
number_t *organise_shop_items(game_t *g);
int get_sell_item_ig(game_t *g, int *qtt);
void sell_item(game_t *g);
void add_gold_nbr(number_t **nums, int qtt, int x, int y);


// travel menu
void travel_menu(game_t *game, sprite_t *bg);
void trvl_menu_display(button_t **btn, sprite_t *bg, sprite_t *brd, game_t *g);
button_t **fill_travel_btn(void);
void travel_menu_state_set(game_t *game);

// pause_menu
void pause_menu(game_t *game, int);
void pause_menu_display(button_t **btn, sprite_t *bg, game_t *g);
button_t **fill_pause_btn(void);
void pause_game_state(game_t *game, int);

// walking
void move_sprite(game_t *g, int scene);
int imobile(player_t *p);
void player_in_screen(player_t *p, int scene, int mv);
void city_in_screen(player_t *p, int mv);
void walk(player_t *p, int delta);
void cave_in_screen(player_t *p, int mv);
void frst_in_screen(player_t *p, int mv);

// other
int delta_fill(game_t *game);
int h_case(void);
int s_case(void);

// misterious_cave
void misterious_cave(game_t *game);
cave_t *cave_fill(void);
void cave_display(cave_t *s, game_t *g);
int cave_can_interact(sprite_t *spr);
void cave_interaction_check(game_t *game, cave_t *city, int delta);
void free_cave(cave_t *cave);
int cave_spawn_time(cave_t *cave);
void cave_particle_handeling(cave_t *cave, int delta);
void moove_hp_bar(player_t *plr, sprite_t *spr);
void handle_cave_music(music_t *music);

// forest_of_trees
void forest_of_trees(game_t *game);
forest_t *forest_fill(void);
void forest_display(forest_t *f, game_t *g);
int forest_can_interact(sprite_t *spr);
void forest_interaction_check(game_t *g, forest_t *f, int delta);
void add_tree(tree_t **tree);
tree_t *fill_next_tree(void);
void chop_tree(game_t *g, tree_t **tree);
void advance_tree_quest(game_t *g);
void handle_forest_music(music_t *music);
void forest_particle_handeling(forest_t *f, int delta);

// settings
void settings(game_t *game, int);
void settings_display(button_t **btn, sprite_t *bg, game_t *g);
button_t **fill_settings_btn(void);
void toggle_music(game_t *game, int music_num);
void change_volume(music_t *music, int change, int music_num);
void change_settings(game_t *game, int music_num);

// enemy
void spawn_enemy(enemy_t **e);
enemy_t *new_enemy(void);
void move_enemy(sprite_t *plr, enemy_t *en, int delta, int t);
int enemies_fainting(game_t *g, cave_t *cave);

// attacks
void add_fist(attack_t **atk, player_t *plr);
void attack_handeling(game_t *g, cave_t *cave, int delta);
void attack_move(attack_t *atk, int delta);
void remove_attacks(cave_t *c);
void atk_collision_check(game_t *g, cave_t *c);
void add_enemy_attack(cave_t *cave, enemy_t *enemy, sprite_t *spr);
void remove_lair_attacks(lair_t *l);
void attack_handeling_lair(game_t *g, lair_t *lair, int delta);
void add_dragon_attack(lair_t *lair);
void atk_lair_collision_check(game_t *g, lair_t *lair);
int atck_hits_plr(attack_t *atk, player_t *plr);
void add_weapond_atk(game_t *g, attack_t **atk);

// player fainting
void fainting_scene(game_t *game);
sprite_t **fainting_fill(void);
void fainting_display(sprite_t **spr, game_t *g);
void map_rerect(int delta, sprite_t *map);

// level_up
void level_up_check(game_t *g);

// dragon_lair
void dragon_lair(game_t *game);
void lair_interaction_check(game_t *g, lair_t *lair, int delta);
void lair_display(lair_t *lair, game_t *g);
lair_t *lair_fill(int spawn_dragon);
void move_dragon(lair_t *lair, int delta);
void check_for_dragon_faint(lair_t *lair, game_t *g);
void handle_lair_music(music_t *music);

// particles
void add_particles(particle_t **partcl, char *img, int size);
particle_t *fill_next_particle(char *img, int size);

// inventory
void add_item(bag_t *bag, int item_id, int quantity);
void add_in_hand_item(bag_t *bag, int id);
char *get_item_spr(int id);

// inventory menu
void inventory_menu(game_t *game, sprite_t *bg);
void inventory_display(sprite_t *bg, bag_scene_t *inv, game_t *g);
number_t *organise_inventory_items(game_t *g);
void add_bag_nums(number_t **nums, int qtt, int spot);
bag_scene_t *fill_bag_scene(game_t *g);
void free_bag_scene(bag_scene_t *inv);
void add_one_bag_num(number_t *nbr, int x, int y, int n);
int selected_is_usable(int id);
int selected_is_weapond(int id);
void item_select_check(game_t *g, bag_scene_t *inv);
void use_selected_item(game_t *g, bag_scene_t *inv);
void change_in_hand(game_t *g, int id);
void add_stats_nums(number_t **nums, player_t *plr);

// ho_to_play
void how_to_play(game_t *game);
sprite_t **fill_toturial(void);
void tuto_menu_display(sprite_t **bg, game_t *g, int spot);

// cinematic
void win_cinematic(game_t *game);
void move_cinematic_spr(sprite_t **spr, sfVector2f *scale, float *angl, int d);
void display_cinematic(game_t *g, sprite_t **spr);
sfVector2f set_basic_scale(void);
sprite_t **fill_cinematic_spr(void);

// check opens
int open_check(char *str);
int check_even_more_opens(void);
int check_all_opens(void);

#endif /* !HEADER */
