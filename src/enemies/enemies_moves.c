/*
** EPITECH PROJECT, 2019
** enemies_move
** File description:
** rpg
*/

#include "rpg.h"
#include "struct.h"
#include "enum.h"

void move_rect_possible(game_scene_t *scenes, int tmp,
                        game_setting_t *settings)
{
    if (scenes[settings->current].objs[tmp].rect.left < 48)
        scenes[settings->current].objs[tmp].rect.left += 16;
    else if (scenes[settings->current].objs[tmp].rect.top != 128)
        scenes[settings->current].objs[tmp].rect.left = 0;
    if (scenes[settings->current].objs[tmp].rect.top == 128)
        scenes[settings->current].objs[tmp].rect.left += 16;
    sfSprite_setTextureRect(scenes[settings->current].objs[tmp].sprite,
                            scenes[settings->current].objs[tmp].rect);
}

void move_rect_enemies(game_scene_t *scenes,
    game_stat_t *stats, int tmp, game_setting_t *settings)
{
    sfVector2f vector = sfSprite_getPosition(
    scenes[settings->current].objs[tmp].sprite);

    if (((stats->player.position.y < vector.y
        && stats->player.position.y > vector.y - 700)
        || (stats->player.position.y > vector.y
        && stats->player.position.y < vector.y + 700))
        && ((stats->player.position.x < vector.x
        && stats->player.position.x > vector.x - 700)
        || (stats->player.position.x > vector.x
        && stats->player.position.x < vector.x + 700))) {
        move_rect_possible(scenes, tmp, settings);
    }
}

void enemies_move_to_player(game_t *game, int tmp, float delta_time)
{
    sfVector2f vector = sfSprite_getPosition(
    game->scenes[game->settings->current].objs[tmp].sprite);

    if (((game->stats->player.position.y < vector.y
        && game->stats->player.position.y > vector.y - 700)
        || (game->stats->player.position.y > vector.y
        && game->stats->player.position.y < vector.y + 700))
        && ((game->stats->player.position.x < vector.x
        && game->stats->player.position.x > vector.x - 700)
        || (game->stats->player.position.x > vector.x
        && game->stats->player.position.x < vector.x + 700))) {
        rect_chose(vector, game, tmp);
        enemies_positions(game, tmp, delta_time);
    }
}

void enemies_detect_player(game_t *game)
{
    if (game->settings->current == BEACH)
        for (int tmp = SKELETON1_O_S4; tmp <= SKELETON20_O_S4; tmp++)
            if (game->scenes[BEACH].objs[tmp].speed > 0)
                enemies_move_to_player(game, tmp, game->settings->delta_time);
    if (game->settings->current == CAMP)
        for (int tmp = GOLEM1_O_S5; tmp <= GOLEM10_O_S5; tmp++)
            if (game->scenes[CAMP].objs[tmp].speed > 0)
                enemies_move_to_player(game, tmp, game->settings->delta_time);
    if (game->settings->current == FOREST)
        for (int tmp = GHOST1_O_S3; tmp <= GHOST15_O_S3; tmp++)
            if (game->scenes[FOREST].objs[tmp].speed > 0)
                enemies_move_to_player(game, tmp, game->settings->delta_time);
    if (game->settings->current == BOSS &&
        game->scenes[BOSS].objs[SHAMAN_O_S2].speed > 0)
        enemies_move_to_player(game, SHAMAN_O_S2, game->settings->delta_time);
}
