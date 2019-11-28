# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epainter <epainter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 13:22:33 by epainter          #+#    #+#              #
#    Updated: 2019/11/25 10:35:22 by epainter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	$(MAKE) -C minilibx_macos
	$(MAKE) -C libft
	gcc -Wall -Wextra -Werror srcs/matrix_trasformations/*.c srcs/math_func/*.c srcs/map\ scan/*.c srcs/errors/*.c srcs/*.c srcs/color\ transformation/*.c srcs/Bresenham\'s\ algorithm/*.c -I./srcs/map\ scan -I./libft -I./srcs -L./libft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -lft