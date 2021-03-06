/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_interaction
*/

#include "rpg.h"
#include "struct.h"
#include "enum.h"
#include "define.h"

void play_song_walk(game_scene_t scenes, game_setting_t *settings)
{
    if (settings->last_time < (settings->timers.walk + 3))
        return;
    else
        settings->timers.walk = settings->last_time;
    if (settings->current == TOWN)
        sfMusic_play(scenes.sounds[WALK_S_S1].music);
    if (settings->current == BEACH)
        sfMusic_play(scenes.sounds[WALK_S_S4].music);
    if (settings->current == CAMP)
        sfMusic_play(scenes.sounds[WALK_S_S5].music);
    if (settings->current == FOREST)
        sfMusic_play(scenes.sounds[WALK_S_S3].music);
}

int equiped_or_not(game_inventory_t *inventory, int item)
{
    for (int tmp = SLOT_0; tmp <= SLOT_4; tmp++) {
        if (inventory[tmp]._selected == true
            && inventory[tmp].content == item)
            return 1;
    }
    return 0;
}

void player_interaction_attack(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == false &&
        sfKeyboard_isKeyPressed(sfKeyS) == false &&
        sfKeyboard_isKeyPressed(sfKeyQ) == false &&
        sfKeyboard_isKeyPressed(sfKeyD) == false) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) == true &&
            (equiped_or_not(game->inventory, SWORD1_R) == 1 ||
            equiped_or_not(game->inventory, SWORD2_R) == 1)) {
            sfMusic_play(game->scenes[TOWN].sounds[SWORD_S_S1].music);
            player_attack(game->stats);
        } else
            player_stop_moving(game->stats, game->settings);
    }
}

void player_interaction(game_t *game)
{
    if (game->settings->current == MAIN_MENU)
        return;
    if (game->settings->_paused == false) {
        player_interaction_attack(game);
        if ((sfKeyboard_isKeyPressed(sfKeyZ) == true ||
            sfKeyboard_isKeyPressed(sfKeyS) == true ||
            sfKeyboard_isKeyPressed(sfKeyQ) == true ||
            sfKeyboard_isKeyPressed(sfKeyD) == true) &&
            sfKeyboard_isKeyPressed(sfKeySpace) == false)
            key_to_move_or_not(game->scenes[game->settings->current],
            game->settings, game->stats, game->inventory);
    }
}
