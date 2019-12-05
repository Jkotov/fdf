/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/12/05 15:19:57 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include "libft.h"

void	draw(t_trasform_params p)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(p.mlx, p.window);
	ft_bzero(p.img_data, WIN_SIZE_X * WIN_SIZE_Y * 4);
	while (p.map[++i + 1])
	{
		j = -1;
		while (p.map[i][++j + 1].is_exist == 1 && p.map[i][j].is_exist == 1)
		{
			if (p.map[i][j].color == 0xff0000)
				p.map[i][j].color = 0x0000ff;
			if (p.map[i + 1][j].color == 0xff000000)
				p.map[i + 1][j].color = 0xff0000;
			if (p.map[i + 1][j].is_exist == 1 && (all_trasforms(p.map[i][j], p).x <= WIN_SIZE_X && all_trasforms(p.map[i + 1][j], p).y <= WIN_SIZE_Y))
			{
				line(all_trasforms(p.map[i][j], p), all_trasforms(p.map[i + 1][j], p), p.img_data);
				if (!p.map[i][j + 1].z && p.map[i][j + 1].is_exist == 1)
					line(all_trasforms(p.map[i][j], p), all_trasforms(p.map[i][j + 1], p), p.img_data);
			}
		}
	}
	mlx_put_image_to_window(p.mlx, p.window, p.img, 0, 0);
}

void	print_menu(t_trasform_params p)
{
	mlx_string_put(p.mlx, p.window, 1500, 20, 0xffFFFFFF, "MOVE: ARROW");
	mlx_string_put(p.mlx, p.window, 1500, 40, 0xffFFFFFF, "ZOOM: -/+");
	mlx_string_put(p.mlx, p.window, 1500, 60, 0xffFFFFFF, "ROTATE: X: 4/6 Y: 2/8 Z: 1/9");
	mlx_string_put(p.mlx, p.window, 1500, 80, 0xffFFFFFF, "EXIT: ESC");
}

int		main(int argc, char **argv)
{
	t_trasform_params	params;

	int bit_depth = 32;
	int line = WIN_SIZE_X;
	int endian = 0;
	if (argc != 2)
		read_map_error();
	params.map = map_scan(argv[1]);
	params.mlx = mlx_init();
	params.window= mlx_new_window(params.mlx, WIN_SIZE_X, WIN_SIZE_Y, "fdf_test_screen");
	params.shift.x = SHIFTX;
	params.shift.y = SHIFTY;
	params.shift.z = SHIFTZ;
	params.size = SIZE;
	params.angle_x = M_PI / 3;
	params.angle_y = 0;
	params.angle_z = M_PI / 6;
	params.img = mlx_new_image(params.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	params.img_data = (int*)mlx_get_data_addr(params.img, &bit_depth, &line, &endian);
	mlx_put_image_to_window(params.mlx, params.window, params.img, 0, 0);
	draw(params);
	print_menu(params);
	push_control(&params);
	//mlx_pixel_put(params.mlx, params.window, 1, 1, 0xffff);
	mlx_loop(params.mlx);
}
