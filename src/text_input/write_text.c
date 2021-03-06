/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** write_text
*/

#include "rpg.h"
#include "struct.h"
#include "enum.h"

int digit_entered(game_setting_t *settings)
{
    if (settings->event.text.unicode >= '0' &&
    settings->event.text.unicode <= '9')
        return settings->event.text.unicode;
    if (settings->event.text.unicode == 8)
        return -1;
    return 0;
}

int text_entered(game_setting_t *settings)
{
    if (settings->event.text.unicode >= 'a' &&
    settings->event.text.unicode <= 'z')
        return settings->event.text.unicode - 32;
    if ((settings->event.text.unicode >= '0' &&
    settings->event.text.unicode <= '9') ||
    (settings->event.text.unicode >= 'A' &&
    settings->event.text.unicode <= 'Z'))
        return settings->event.text.unicode;
    if (settings->event.text.unicode == 8)
        return -1;
    return 0;
}

void enter_player_name(game_stat_t *stats, game_setting_t *settings)
{
    char entered = '\0';

    if (my_strcmp(sfText_getString(stats->name_t.text), "'PLAYER'") == 1)
        sfText_setString(stats->name_t.text, "");
    entered = text_entered(settings);
    if (entered == -1)
        sfText_setString(stats->name_t.text,
        my_strrem(sfText_getString(stats->name_t.text)));
    else if (my_strlen(sfText_getString(stats->name_t.text)) < 11)
        sfText_setString(stats->name_t.text,
        my_stradd(sfText_getString(stats->name_t.text), entered));
}

int enter_quest_answer(game_text_t quest_answer, game_setting_t *settings)
{
    char entered = '\0';

    entered = digit_entered(settings);
    if (entered == -1) {
        if (my_strlen(sfText_getString(quest_answer.text)) > 16)
            sfText_setString(quest_answer.text,
            my_strrem(sfText_getString(quest_answer.text)));
    } else if (my_strlen(sfText_getString(quest_answer.text)) < 19) {
        sfText_setString(quest_answer.text,
        my_stradd(sfText_getString(quest_answer.text), entered));
    }
    if (my_strcmp(sfText_getString(quest_answer.text), "ENTER A DIGIT : 5"))
        return 1;
    return 0;
}
