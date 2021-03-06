/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_inventory
*/

#include "rpg.h"
#include "struct.h"
#include "enum.h"

void button_inventory5(game_inventory_t *inventory, game_scene_t *scenes,
int enable, int disable)
{
    scenes[CAMP].texts[VOLUME_T_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].texts[FRAME_T_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].texts[FRAME_T_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].texts[FRAME_T_S3].state = ((enable == 1) ? disable : enable);
    scenes[BEACH].texts[FRAME_T_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].texts[FRAME_T_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].texts[VSYNC_T_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].texts[VSYNC_T_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].texts[VSYNC_T_S3].state = ((enable == 1) ? disable : enable);
    scenes[BEACH].texts[VSYNC_T_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].texts[VSYNC_T_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].texts[NAME_T_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].texts[NAME_T_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].texts[NAME_T_S3].state = ((enable == 1) ? disable : enable);
    scenes[BEACH].texts[NAME_T_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].texts[NAME_T_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].texts[XP_T_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].texts[XP_T_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].texts[XP_T_S3].state = ((enable == 1) ? disable : enable);
    button_inventory6(inventory, scenes, 1, -1);
}

void button_inventory4(game_inventory_t *inventory, game_scene_t *scenes,
int enable, int disable)
{
    scenes[TOWN].buttons[V100_B_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].buttons[V100_B_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].buttons[V100_B_S3].state = ((enable == 1) ? disable :
    enable);
    scenes[BEACH].buttons[V100_B_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].buttons[V100_B_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].buttons[CLOSE_B_S1].state = ((enable == 1) ? enable : disable);
    scenes[BOSS].buttons[CLOSE_B_S2].state = ((enable == 1) ? enable : disable);
    scenes[FOREST].buttons[CLOSE_B_S3].state = ((enable == 1) ? enable :
    enable);
    scenes[BEACH].buttons[CLOSE_B_S4].state = ((enable == 1) ? enable :
    disable);
    scenes[CAMP].buttons[CLOSE_B_S5].state = ((enable == 1) ? enable : disable);
    scenes[TOWN].texts[VOLUME_T_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].texts[VOLUME_T_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].texts[VOLUME_T_S3].state = ((enable == 1) ? disable :
    enable);
    scenes[BEACH].texts[VOLUME_T_S4].state = ((enable == 1) ? disable : enable);
    button_inventory5(inventory, scenes, 1, -1);
}

void button_inventory3(game_inventory_t *inventory, game_scene_t *scenes,
int enable, int disable)
{
    scenes[BEACH].buttons[DESKTOP_B_S4].state = ((enable == 1) ? disable :
    enable);
    scenes[CAMP].buttons[DESKTOP_B_S5].state = ((enable == 1) ? disable :
    enable);
    scenes[TOWN].buttons[ON_B_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].buttons[ON_B_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].buttons[ON_B_S3].state = ((enable == 1) ? disable : enable);
    scenes[BEACH].buttons[ON_B_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].buttons[ON_B_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].buttons[OFF_B_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].buttons[OFF_B_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].buttons[OFF_B_S3].state = ((enable == 1) ? disable : enable);
    scenes[BEACH].buttons[OFF_B_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].buttons[OFF_B_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].buttons[F30_B_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].buttons[F30_B_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].buttons[F30_B_S3].state = ((enable == 1) ? disable : enable);
    scenes[BEACH].buttons[F30_B_S4].state = ((enable == 1) ? disable : enable);
    scenes[CAMP].buttons[F30_B_S5].state = ((enable == 1) ? disable : enable);
    button_inventory4(inventory, scenes, 1, -1);
}

void button_inventory2(game_inventory_t *inventory, game_scene_t *scenes,
int enable, int disable)
{
    scenes[CAMP].objs[OPTION_O_S5].speed = ((enable == 1) ? disable : enable);
    scenes[TOWN].objs[EXIT_O_S1].speed = ((enable == 1) ? disable : enable);
    scenes[BOSS].objs[EXIT_O_S2].speed = ((enable == 1) ? disable : enable);
    scenes[FOREST].objs[EXIT_O_S3].speed = ((enable == 1) ? disable : enable);
    scenes[BEACH].objs[EXIT_O_S4].speed = ((enable == 1) ? disable : enable);
    scenes[CAMP].objs[EXIT_O_S5].speed = ((enable == 1) ? disable : enable);
    scenes[TOWN].buttons[TITLE_B_S1].state = ((enable == 1) ? disable : enable);
    scenes[BOSS].buttons[TITLE_B_S2].state = ((enable == 1) ? disable : enable);
    scenes[FOREST].buttons[TITLE_B_S3].state = ((enable == 1) ? disable :
    enable);
    scenes[BEACH].buttons[TITLE_B_S4].state = ((enable == 1) ? disable :
    enable);
    scenes[CAMP].buttons[TITLE_B_S5].state = ((enable == 1) ? disable : enable);
    scenes[TOWN].buttons[DESKTOP_B_S1].state = ((enable == 1) ? disable :
    enable);
    scenes[BOSS].buttons[DESKTOP_B_S2].state = ((enable == 1) ? disable :
    enable);
    scenes[FOREST].buttons[DESKTOP_B_S3].state = ((enable == 1) ? disable :
    enable);
    button_inventory3(inventory, scenes, 1, -1);
}

void button_inventory1(game_inventory_t *inventory, game_scene_t *scenes,
int enable, int disable)
{
    scenes[TOWN].objs[INVENTORY_O_S1].speed = ((enable == 1) ? enable :
    disable);
    scenes[BOSS].objs[INVENTORY_O_S2].speed = ((enable == 1) ? enable :
    disable);
    scenes[FOREST].objs[INVENTORY_O_S3].speed = ((enable == 1) ? enable :
    disable);
    scenes[BEACH].objs[INVENTORY_O_S4].speed = ((enable == 1) ? enable :
    disable);
    scenes[CAMP].objs[INVENTORY_O_S5].speed = ((enable == 1) ? enable :
    disable);
    scenes[TOWN].objs[ME_O_S1].speed = ((enable == 1) ? disable : enable);
    scenes[BOSS].objs[ME_O_S2].speed = ((enable == 1) ? disable : enable);
    scenes[FOREST].objs[ME_O_S3].speed = ((enable == 1) ? disable : enable);
    scenes[BEACH].objs[ME_O_S4].speed = ((enable == 1) ? disable : enable);
    scenes[CAMP].objs[ME_O_S5].speed = ((enable == 1) ? disable : enable);
    scenes[TOWN].objs[OPTION_O_S1].speed = ((enable == 1) ? disable : enable);
    scenes[BOSS].objs[OPTION_O_S2].speed = ((enable == 1) ? disable : enable);
    scenes[FOREST].objs[OPTION_O_S3].speed = ((enable == 1) ? disable : enable);
    scenes[BEACH].objs[OPTION_O_S4].speed = ((enable == 1) ? disable : enable);
    button_inventory2(inventory, scenes, 1, -1);
}
