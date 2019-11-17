cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(minilibx_macos srcs)

add_library(libmlx STATIC minilibx_macos/mlx_shaders.c minilibx_macos/mlx_new_window.m minilibx_macos/mlx_init_loop.m minilibx_macos/mlx_new_image.m minilibx_macos/mlx_xpm.c minilibx_macos/mlx_int_str_to_wordtab.c)

add_executable(fdf
        srcs/main.c srcs/fdf.h "srcs/Bresenham's algorithm/line.c" srcs/math_func/ft_abs.c srcs/math_func/percentage.c "srcs/color transformation/color_from_arr_to_int.c" "srcs/color transformation/color_from_int_to_arr.c" "srcs/color transformation/color_delta.c" "srcs/color transformation/color_plus_delta_color.c")

target_link_libraries(fdf libmlx "-framework OpenGL" "-framework AppKit" -lmlx)