# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epainter <epainter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 13:22:33 by epainter          #+#    #+#              #
#    Updated: 2019/11/18 09:42:37 by epainter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	$(MAKE) -C minilibx_macos
	gcc -Wall -Wextra -Werror srcs/*.c srcs/Bresenham\'s\ algorithm/line.c -I./srcs -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
