/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** fill scene victory and defeat
*/

#include "rpg.h"
#include "struct.h"
#include "enum.h"
#include "fill_scene.h"

void fill_scene_victory(game_scene_t victory)
{
    victory.buttons[EXIT_B_S6] = new_button("assets/images/exit_menu.png",
    (sfVector2f) {800, 520}, (sfIntRect) {0, 0, 280, 96}, 0);
    victory.buttons[DESKTOP_B_S6] = new_button("assets/images/exit_desktop.png",
    (sfVector2f) {770, 390}, (sfIntRect) {0, 0, 336, 96}, 0);
    victory.objs[LOGO_O_S6] = new_object("assets/images/logo.png",
    (sfVector2f) {560, 50}, (sfIntRect) {0, 0, 803, 285}, 0);
    victory.objs[BG_O_S6] = new_object("assets/images/menu_bg_victory.png",
    (sfVector2f) {0, -50}, (sfIntRect) {0, 0, 1920, 1080}, 0);
    victory.objs[CURSOR_O_S6] = new_object("assets/images/cursor.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 30, 30}, 0);
    victory.texts[VICTORY_T_S6] = new_text("assets/font/font.ttf", "",
    (sfVector2f) {0, 0}, 60);
    victory.sounds[SOUND_S_S6] = new_sound("assets/sounds/victory.ogg", sfFalse,
    100, sfFalse);
}

void fill_scene_defeat(game_scene_t defeat)
{
    defeat.buttons[EXIT_B_S7] = new_button("assets/images/exit_menu.png",
    (sfVector2f) {850, 520}, (sfIntRect) {0, 0, 280, 96}, 0);
    defeat.buttons[DESKTOP_B_S7] = new_button("assets/images/exit_desktop.png",
    (sfVector2f) {820, 390}, (sfIntRect) {0, 0, 336, 96}, 0);
    defeat.objs[LOGO_O_S7] = new_object("assets/images/logo.png",
    (sfVector2f) {560, 50}, (sfIntRect) {0, 0, 803, 285}, 0);
    defeat.objs[BG_O_S7] = new_object("assets/images/menu_bg_defeat.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080}, 0);
    defeat.objs[CURSOR_O_S7] = new_object("assets/images/cursor.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 30, 30}, 0);
    defeat.texts[DEFEAT_T_S7] = new_text("assets/font/font.ttf", "",
    (sfVector2f) {0, 0}, 100);
    defeat.sounds[SOUND_S_S7] = new_sound("assets/sounds/defeat.ogg", sfFalse,
    100, sfFalse);
}
