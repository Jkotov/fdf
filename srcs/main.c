/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/11/28 20:11:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include "libft.h"
#define SIZE 5
#define SHIFTX 200
#define SHIFTY 200
#define SHIFTZ 0
#define ANGLEX 10

int main(int argc, char** argv)
{
	void *mlx_ptr;
	void *window_ptr;
	t_pixel	**map;
	int i;
	int j;

	if (argc != 2)
		read_map_error();
	map = map_scan(argv[1]);
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, "fdf_test_screen");
	i = -1;
	t_trasform_params params;
	params.shift.x = SHIFTX;
	params.shift.y = SHIFTY;
	params.shift.z = SHIFTZ;
	params.size = SIZE;
	params.angle_x = M_PI / 3;
	params.angle_y = 0;
	params.angle_z = M_PI / 6;
	while (map[++i + 1])
	{
		j = -1;
		while (map[i][++j + 1].is_exist == 1 && map[i][j].is_exist == 1)
		{
			if (map[i][j].color == 0xff0000)
				map[i][j].color = 0x0000ff;
			if (map[i + 1][j].color == 0xff000000)
				map[i + 1][j].color = 0xff0000;
			if (map[i + 1][j].is_exist == 1 && (all_trasforms(map[i][j], params).x <= WIN_SIZE_X && all_trasforms(map[i + 1][j], params).y <= WIN_SIZE_Y))
				{
					line(all_trasforms(map[i][j], params), all_trasforms(map[i + 1][j], params), mlx_ptr, window_ptr);
					if (!map[i][j + 1].z && map[i][j + 1].is_exist == 1)
						{
							line(all_trasforms(map[i][j], params), all_trasforms(map[i][j + 1], params), mlx_ptr, window_ptr);
						}
				}
		}
	}
	mlx_pixel_put(mlx_ptr, window_ptr, 1, 1, 0xffff);
	mlx_loop(mlx_ptr);
getchar();
}