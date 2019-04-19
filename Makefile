##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= 	my_rpg

CC		= 	gcc

RM		= 	rm -f

OBJS	= $(SRCS:.c=.o)

SRCS	= 	src/main.c								\
			src/create_game3.c 						\
			src/create_game2.c 						\
			src/create_game.c						\
			src/my_rpg.c							\
			src/player/player_move.c				\
			src/player/player_attack.c				\
			src/player/player_rect.c				\
			src/enemies/enemies_die.c				\
			src/enemies/enemies_moves.c				\
			src/enemies/enemies_positions.c			\
			src/new_content2.c						\
			src/new_content.c						\
			src/quests_interaction.c				\
			src/analyser.c 							\
			src/draw_cursor.c 						\
			src/draw_quest.c						\
			src/set_scale.c 						\
			src/clock.c 							\
			src/my_libc_functions.c 				\
			src/play_sounds.c 						\
			src/buttons/button_event.c 				\
			src/buttons/button_main_menu.c			\
			src/buttons/button_town.c 				\
			src/change/change_main_menu.c			\
			src/change/change_maps.c 				\
			src/change/change_selection_maps.c 		\
			src/change/change_vic_def.c 			\
			src/fill_scene/fill_scene_beach.c		\
			src/fill_scene/fill_scene_boss.c		\
			src/fill_scene/fill_scene_camp.c		\
			src/fill_scene/fill_scene_forest.c	 	\
			src/fill_scene/fill_scene_main_menu.c	\
			src/fill_scene/fill_scene_town1.c		\
			src/fill_scene/fill_scene_town2.c	    \
			src/fill_scene/fill_scene_vic_def.c	   	\
			src/fill_quest/fill_quest0_4.c			\
			src/fill_quest/fill_quest5_9.c			\
			src/fill_quest/fill_quest10_12.c		\
			src/change/change_statics_pos.c

CFLAGS = -Iinclude
CFLAGS += -L./lib/printf -lprintf
CFLAGS += -lcsfml-system -lcsfml-audio -lcsfml-graphics -lcsfml-window
CFLAGS += -W -Wall -Wextra -g
CFLAGS += -lm

LDFLAGS = -L./lib/printf -lprintf
LDFLAGS += -lcsfml-system -lcsfml-audio -lcsfml-graphics -lcsfml-window
LDFLAGS += -W -Wall -Wextra -g
LDFLAGS += -lm

all: mklib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	cd lib/printf && make clean

fclean: clean
	$(RM) $(NAME)
	$(RM) *~ -f $(NAME)
	$(RM) *# -f $(NAME)
	cd lib/printf && make fclean

mklib:
	cd lib/printf && make

re	: 	fclean all

.PHONY	: 	all clean fclean re
