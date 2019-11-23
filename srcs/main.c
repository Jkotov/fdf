/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/11/23 03:43:42 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include "libft.h"
#define SIZE 30
int main(int argc, char** argv)
{
	void *mlx_ptr;
	void *window_ptr;
	t_pixel pixel_start;
	t_pixel pixel_end;
	t_pixel	**map;
	int i;
	int j;

	if (argc != 2)
		read_map_error();
	map = map_scan(argv[1]);
	pixel_start.x = WIN_SIZE_X / 2;
	pixel_start.y = WIN_SIZE_Y / 2;
	pixel_start.color = 0x008b00ff;
	pixel_end.color = 0x0090ee90;
	pixel_end.x = 0;
	pixel_end.y = 3;
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, "fdf_test_screen");
	/*while (pixel_end.x++ < WIN_SIZE_X)
		line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = WIN_SIZE_X / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = WIN_SIZE_X;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.y = WIN_SIZE_Y / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.y = WIN_SIZE_Y;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = WIN_SIZE_X / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = 0;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.y = WIN_SIZE_Y / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);*/
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j].is_exist)
		{
			if (map[i][j].color == 0xff000000)
				map[i][j].color = 0xff0000;
			if (!map[i][j].z)
			mlx_pixel_put(mlx_ptr, window_ptr, SIZE * map[i][j].x, (SIZE * map[i][j].y - map[i][j].z), map[i][j].color);
		}
	}
	mlx_pixel_put(mlx_ptr, window_ptr, 1, 1, 0xffff);
	mlx_loop(mlx_ptr);
}