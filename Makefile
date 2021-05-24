# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 21:13:20 by gselyse           #+#    #+#              #
#    Updated: 2021/03/25 16:35:35 by gselyse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER		= -I includes/
FLAGS		= -Wextra -Wall -Werror
CC			=	gcc

SRC			=	srcs/main.c srcs/player.c srcs/validation.c srcs/checking.c srcs/map.c\
				srcs/parsing.c srcs/keyhook.c srcs/display.c \
				srcs/utils_two.c srcs/raycast.c srcs/textures.c \
				srcs/wall_hit_w.c srcs/wall_hit_h.c srcs/free_function.c \
				srcs/valid_sprites.c srcs/sprites.c srcs/utils.c srcs/utils_three.c \
				srcs/screenshot.c srcs/color.c srcs/resolution.c srcs/init.c

OBJ 		= $(SRC:.c=.o)

all : $(NAME)

.c.o:
			@${CC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}
			@echo "Compile : "$< "\033[32mok\033[0m"

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(FLAGS) $(HEADER) $(OBJ) -o $(NAME) -L libft/ -lft -L./minilibx -lmlx -lXext -lX11 -lm
	@echo "\r$(FGREEN) Cub3D is ready!"

clean:
	rm -rf $(OBJ) $(B_OBJ)
	rm -rf save.bmp

fclean: clean
	@make fclean -C libft/
	rm -rf $(NAME)
	rm -rf libft/libft.a

re: fclean all

test:	
	./$(NAME) maps/map.cub

screenshot:
	./$(NAME) maps/map.cub --save

.PHONY:	all clean fclean re

# **************************************************************************** #
#								Utilits										   #
# **************************************************************************** #

# Цвета шрифта
FBLACK		= \033[30m
FRED		= \033[31m
FGREEN		= \033[32m
FYELLOW		= \033[33m
FBLUE		= \033[34m
FMAGENTA	= \033[35m
FCYAN		= \033[36m
FGREY		= \033[37m

# Цвета фона
BGBLACK		= \033[40m
BGRED		= \033[41m
BGGREEN		= \033[42m
BGYELLOW	= \033[43m
BGBLUE		= \033[44m
BGMAGENTA	= \033[45m
BGCYAN		= \033[46m
BGGREY		= \033[47m

# Свойства текста
PBOLD		= \033[1m#	жирный шрифт
PDBOLD		= \033[2m#	полу яркий цвет
PNBOLD		= \033[22m#	нормальная интенсивность
PUNDERLINE	= \033[4m#	подчеркивание
PBLINK		= \033[5m#	мигание
PINVERSE	= \033[7m#	инверсия
PNULL		= \033[0m#	отмена

PRINT		= printf
