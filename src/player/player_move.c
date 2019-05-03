/*
** EPITECH PROJECT, 2019
** player_move
** File description:
** my_rpg
*/

#include "rpg.h"
#include "struct.h"
#include "enum.h"

void player_stop_moving(game_stat_t *stats, game_setting_t *settings)
{
    stats->player.rect.width = 16;
    stats->player.rect.height = 32;
    if (stats->player.rect.top == 157 && stats->player.rect.left == 0)
        stats->player.rect.top = 0;
    if (stats->player.rect.top == 157 && stats->player.rect.left == 16)
        stats->player.rect.top = 64;
    if (stats->player.rect.top == 129 && stats->player.rect.left == 0) {
        stats->player.position.y -= 4;
        stats->player.rect.top = 32;
    }
    if (stats->player.rect.top == 129 && stats->player.rect.left == 32) {
        stats->player.position.y -= 40 * settings->delta_time;
        stats->player.position.x += 500 * settings->delta_time;
        stats->player.rect.top = 96;
    }
    stats->player.rect.left = 0;
    sfSprite_setPosition(stats->player.sprite, stats->player.position);
    sfSprite_setTextureRect(stats->player.sprite, stats->player.rect);
}

int bordure_crossed(game_setting_t *settings, game_stat_t *stats,
    game_inventory_t *inventory)
{
    const sfView *view = sfRenderWindow_getView(settings->window);
    sfVector2f vector_view = sfView_getCenter(view);
    int speed = 4;

    if (equiped_or_not(inventory, BOOTS_R) == 1)
        speed += 1;
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (stats->player.position.x + 4 >= (vector_view.x - 960) + 1900)
            return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (stats->player.position.y + 4 >= (vector_view.y - 540) + 870)
            return 1;
    }
    return 0;
}

void move_window(game_setting_t *settings, game_stat_t *stats,
    game_inventory_t *inventory)
{
    const sfView *view = sfRenderWindow_getView(settings->window);
    sfVector2f vector_view = sfView_getCenter(view);
    int speed = 40;

    if (settings->current == CAMP || settings->current == BEACH
        || settings->current == BOSS)
        return;
    if (equiped_or_not(inventory, BOOTS_R) == 1)
        speed += 10;
    if (player_pos_view(vector_view, stats) == 1) return;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        if (vector_view.x < 3390)
            vector_view.x += speed * settings->delta_time;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        if (vector_view.x > 960)
            vector_view.x -= speed * settings->delta_time;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        if (vector_view.y > 540)
            vector_view.y -= speed * settings->delta_time;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        if (vector_view.y < 3225)
            vector_view.y += speed * settings->delta_time;
    change_vector_view(settings, vector_view);
}

void move_player(game_setting_t *settings, game_stat_t *stats,
    game_inventory_t *inventory)
{
    int speed = 40;

    if (equiped_or_not(inventory, BOOTS_R) == 1)
        speed += 10;
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        stats->player.position.x += speed * settings->delta_time;
        stats->player.rect.top = 32;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (stats->player.position.x - 4 > 10)
            stats->player.position.x -= speed * settings->delta_time;
        stats->player.rect.top = 96;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (stats->player.position.y - 4 > 10)
            stats->player.position.y -= speed * settings->delta_time;
        stats->player.rect.top = 64;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        stats->player.position.y += speed * settings->delta_time;
        stats->player.rect.top = 0;
    }
}

void key_to_move_or_not(game_scene_t scenes, game_setting_t *settings,
    game_stat_t *stats, game_inventory_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)
        || sfKeyboard_isKeyPressed(sfKeyQ)
        || sfKeyboard_isKeyPressed(sfKeyZ)
        || sfKeyboard_isKeyPressed(sfKeyS)) {
        if (player_is_on_rectangle(settings, stats, scenes) == 0)
            return;
        move_window(settings, stats, inventory);
        play_song_walk(scenes, settings);
        if (bordure_crossed(settings, stats, inventory) == 1)
            return;
        move_player(settings, stats, inventory);
        sfSprite_setPosition(stats->player.sprite, stats->player.position);
        sfSprite_setTextureRect(stats->player.sprite, stats->player.rect);
    }
}
