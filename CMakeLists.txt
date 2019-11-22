cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(minilibx_macos srcs libft)

add_library(libmlx STATIC
        minilibx_macos/mlx_shaders.c
        minilibx_macos/mlx_new_window.m
        minilibx_macos/mlx_init_loop.m
        minilibx_macos/mlx_new_image.m
        minilibx_macos/mlx_xpm.c
        minilibx_macos/mlx_int_str_to_wordtab.c)
add_library(libft STATIC
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strjoinfree.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h libft/ft_atoi_base.c)

add_executable(fdf
        srcs/main.c
        srcs/fdf.h
        "srcs/Bresenham's algorithm/line.c"
        srcs/math_func/ft_abs.c srcs/math_func/percentage.c
        "srcs/color transformation/color_from_arr_to_int.c"
        "srcs/color transformation/color_from_int_to_arr.c"
        "srcs/color transformation/color_delta.c"
        "srcs/color transformation/color_plus_delta_color.c"
        "srcs/color transformation/color_inc.c"
        "srcs/color transformation/free_color_and_delta.c"
        "srcs/Bresenham's algorithm/vert_line.c"
        "srcs/Bresenham's algorithm/init_start_values.c"
        "srcs/map scan/read_map.c"
        "srcs/map scan/map_scan.h"
        srcs/errors/read_map_error.c
        "srcs/map scan/string_to_tokens.c" "srcs/map scan/tokens_to_matrix.c")

target_link_libraries(fdf libmlx "-framework OpenGL" "-framework AppKit" -lmlx libft)