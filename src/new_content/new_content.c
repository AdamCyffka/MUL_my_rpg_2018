/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** new content
*/

#include "rpg.h"
#include "struct.h"

game_button_t new_button(const char *path_to_img,
    sfVector2f pos, sfIntRect rect, int state)
{
    game_button_t button;

    button.shape = sfRectangleShape_create();
    button.texture = sfTexture_createFromFile(path_to_img, NULL);
    button.position = pos;
    button.rect = rect;
    button.state = state;
    button.content = 0;
    button.action = 0;
    sfRectangleShape_setTexture(button.shape, button.texture, sfTrue);
    sfRectangleShape_setTextureRect(button.shape, button.rect);
    sfRectangleShape_setPosition(button.shape, pos);
    sfRectangleShape_setSize(button.shape, (sfVector2f) {rect.width, rect
    .height});
    return (button);
}

game_sound_t new_sound(const char *path_to_sound, sfBool state, float volume,
bool _activated)
{
    game_sound_t sound;
    sound.music = sfMusic_createFromFile(path_to_sound);
    sound._loop = state;
    sound._activated = _activated;
    sfMusic_setLoop(sound.music, state);
    sfMusic_setVolume(sound.music, volume);
    return (sound);
}

game_object_t new_object(const char *path_to_spsheet,
sfVector2f pos, sfIntRect rect, float speed)
{
    game_object_t obj;

    obj.state = 0;
    obj.speed = speed;
    obj.sprite = sfSprite_create();
    obj.texture = sfTexture_createFromFile(path_to_spsheet, NULL);
    obj.position = pos;
    obj.rect = rect;
    sfSprite_setTexture(obj.sprite, obj.texture, sfTrue);
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    sfSprite_setPosition(obj.sprite, pos);
    return (obj);
}

int *new_scene2(int nb_objs, int nb_musics, int nb_buttons, int nb_texts)
{
    int *how_many = malloc(sizeof(int) * 4);

    if (how_many == NULL)
        return NULL;
    how_many[0] = nb_objs;
    how_many[1] = nb_musics;
    how_many[2] = nb_buttons;
    how_many[3] = nb_texts;
    return how_many;
}

game_scene_t new_scene(int nb_objs, int nb_musics, int nb_buttons, int nb_texts)
{
    game_scene_t new_scene;

    new_scene.objs = malloc(sizeof(game_object_t) * nb_objs);
    if (new_scene.objs == NULL)
        return (game_scene_t) {0};
    new_scene.sounds = malloc(sizeof(game_sound_t) * nb_musics);
    if (new_scene.sounds == NULL)
        return (game_scene_t) {0};
    new_scene.buttons = malloc(sizeof(game_button_t) * nb_buttons);
    if (new_scene.buttons == NULL)
        return (game_scene_t) {0};
    new_scene.texts = malloc(sizeof(game_text_t) * nb_texts);
    if (new_scene.texts == NULL)
        return (game_scene_t) {0};
    new_scene.how_many = malloc(sizeof(int) * 4);
    if (new_scene.how_many == NULL)
        return (game_scene_t) {0};
    new_scene.how_many = new_scene2(nb_objs, nb_musics, nb_buttons, nb_texts);
    return (new_scene);
}
