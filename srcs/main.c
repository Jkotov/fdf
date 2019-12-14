/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/12/14 16:23:55 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	print_menu(t_map p)
{
	mlx_string_put(p.mlx, p.window, 1500, 20, 0xffFFFFFF, "MOVE: ARROW");
	mlx_string_put(p.mlx, p.window, 1500, 40, 0xffFFFFFF, "ZOOM: -/+");
	mlx_string_put(p.mlx, p.window, 1500,\
	60, 0xffFFFFFF, "ROTATE: X: 4/6 Y: 2/8 Z: 1/9");
	mlx_string_put(p.mlx, p.window, 1500, 80, 0xffFFFFFF, "EXIT: ESC");
}

int		main(int argc, char **argv)
{
	t_trasform_params	params;
	t_map				map;

	if (argc != 2)
		read_map_error();
	map = map_scan(argv[1]);
	params.shift.x = SHIFTX;
	params.shift.y = SHIFTY;
	params.shift.z = SHIFTZ;
	params.size = SIZE;
	params.angle_x = M_PI / 3;
	params.angle_y = 0;
	params.angle_z = M_PI / 6;
	mlx_put_image_to_window(map.mlx, map.window, map.img, 0, 0);
	draw(map, params);
	print_menu(map);
	push_control(&map, &params);
	mlx_loop(map.mlx);
}
