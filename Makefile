# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epainter <epainter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 18:47:50 by epainter          #+#    #+#              #
#    Updated: 2019/12/18 19:26:10 by epainter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = ./srcs/Bresenhams_algorithm/init_start_values.c \
	./srcs/Bresenhams_algorithm/line.c \
	./srcs/Bresenhams_algorithm/put_pixel.c \
	./srcs/Bresenhams_algorithm/vert_line.c \
	./srcs/color_transformation/color_delta.c \
	./srcs/color_transformation/color_from_arr_to_int.c \
	./srcs/color_transformation/color_from_int_to_arr.c \
	./srcs/color_transformation/color_inc.c \
	./srcs/color_transformation/color_plus_delta_color.c \
	./srcs/color_transformation/color_set.c \
	./srcs/color_transformation/free_color_and_delta.c \
	./srcs/control/keyboard_color.c \
	./srcs/control/keyboard_projetion.c \
	./srcs/control/push_control.c \
	./srcs/control/push_key.c \
	./srcs/control/push_mouse.c \
	./srcs/draw_map/draw_map.c \
	./srcs/errors/read_map_error.c \
	./srcs/main.c \
	./srcs/map_scan/map_scan.c \
	./srcs/map_scan/matrix_new.c \
	./srcs/map_scan/read_map.c \
	./srcs/map_scan/string_to_tokens.c \
	./srcs/map_scan/tokens_to_matrix.c \
	./srcs/math_func/ft_abs.c \
	./srcs/math_func/percentage.c \
	./srcs/matrix_trasformations/all_trasforms.c \
	./srcs/matrix_trasformations/central_projection.c \
	./srcs/matrix_trasformations/find_center.c \
	./srcs/matrix_trasformations/move.c \
	./srcs/matrix_trasformations/resize.c \
	./srcs/matrix_trasformations/rotate_around_x.c \
	./srcs/matrix_trasformations/rotate_around_y.c \
	./srcs/matrix_trasformations/rotate_around_z.c \
	./srcs/matrix_trasformations/transform_params_init.c

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libft/ \
	-I./minilibx_macos/ \
	-I./minilibx_macos/ \
	-I./minilibx_macos/ \
	-I./srcs/control/ \
	-I./srcs/ \
	-I./srcs/map/scan/

LIBSINC = -L./libft/ \
	-L./minilibx_macos/

LIBFTPATH = ./libft/
MINILIBXPATH = ./minilibx_macos/

LIBS = -lft \
	-lmlx

LIBSNAME = libft.a \
	libmlx.a
INCNAME = ./srcs/control/control.h  \
	./srcs/fdf.h \
	./srcs/map_scan/map_scan.h


all: $(NAME)

%.o: %.c $(INCNAME)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(MINILIBXPATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBSINC) $(LIBS) -framework OpenGL -framework AppKit

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MINILIBXPATH)
	/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
