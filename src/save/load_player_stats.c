/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** load player stats
*/

#include "rpg.h"
#include "struct.h"

static int store_player_stat(FILE *file, int *nb)
{
	char *str = NULL;
	size_t i = 0;
	int last_elem;
	char **array;

	if (getline(&str, &i, file) == -1)
		return (WRONG_CONFIG_PATH);
	array = split(str, "= \n");
	last_elem = my_arrlen((void **)array) - 1;
	if (last_elem == -1 || !my_str_isnum(array[last_elem]))
		return (WRONG_CONFIG_PATH);
	*nb = my_atoi(array[last_elem]);
	free_array((void **)array);
	free(str);
	return (SUCCESS);
}

int load_player_stats(player_t *player)
{
	FILE *file = fopen("data/player_stats.cfg", "r");

	if (file == NULL)
		return (WRONG_PATH);
	(store_player_stat(file, &player->stats->level));
	(store_player_stat(file, &player->stats->xp));
	(store_player_stat(file, &player->stats->xp_to_up));
	(store_player_stat(file, &player->stats->light_radius));
	(store_player_stat(file, &player->stats->nb_orbe));
	return (SUCCESS);
}
