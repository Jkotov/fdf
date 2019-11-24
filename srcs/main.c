/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/11/24 14:19:48 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include "libft.h"
#define SIZE 15
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
	while (map[++i + 1])
	{
		j = -1;
		while (map[i][++j + 1].is_exist == 1 && map[i][j].is_exist == 1)
		{
			if (map[i][j].color == 0xff0000)
				map[i][j].color = 0x0000ff;
			if (map[i + 1][j].color == 0xff000000)
				map[i + 1][j].color = 0xff0000;
				if (map[i + 1][j].is_exist == 1)
				{
					line(resize(map[i][j], SIZE), resize(map[i + 1][j], SIZE), mlx_ptr, window_ptr);
				if (!map[i][j + 1].z && map[i][j + 1].is_exist == 1)
				{
					line(resize(map[i][j], SIZE), resize(map[i][j + 1], SIZE), mlx_ptr, window_ptr);
				}
			}
		}
	}
	mlx_pixel_put(mlx_ptr, window_ptr, 1, 1, 0xffff);
	mlx_loop(mlx_ptr);
	getchar();
}