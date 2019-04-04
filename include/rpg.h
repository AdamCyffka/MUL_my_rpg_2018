/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** rpg.h
*/

#ifndef RPG_H_
#define RPG_H_

#include "printf.h"
#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int main(int ac, char **av, char **env);
int my_rpg(void);

//fill_scene
void fill_scene_beach1(game_scene_t beach);
void fill_scene_boss1(game_scene_t boss);
void fill_scene_forest1(game_scene_t forest);
void fill_scene_main_menu1(game_scene_t main_menu);
void fill_scene_camp1(game_scene_t camp);
void fill_scene_town1(game_scene_t town);
void fill_scene_town6(game_scene_t town);
void fill_scene_victory(game_scene_t victory);
void fill_scene_defeat(game_scene_t defeat);

//create_game2
void create_scenes(game_scene_t *scenes);
void create_inventory(game_inventory_t *inventory);
void create_quests(game_quest_t *quests);
void create_stats(game_stat_t *stats);
void create_settings(game_setting_t *settings);

//init
void init_window(game_setting_t *params);
game_t *create_game();
game_scene_t new_scene(int nb_objs, int nb_musics, int nb_buttons, int
nb_texts);
game_text_t new_text(const char *path_to_font, const char *towrite,
                     sfVector2f pos, int size);
game_button_t new_button(const char *path_to_img,
                         sfVector2f pos, sfIntRect rect, int state);
game_sound_t new_sound(const char *path_to_sound, sfBool state, float volume);
game_object_t new_object(const char *path_to_spsheet, sfVector2f pos,
                         sfIntRect rect, float speed);
//destroy
void destroy_all(game_t **game);
#endif /* RPG_H_ */
