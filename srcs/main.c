/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/12/15 21:26:24 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	print_menu(t_map p)
{
	mlx_string_put(p.mlx, p.window, 1500, 20, 0xffffff, "MOVE: ARROW");
	mlx_string_put(p.mlx, p.window, 1500, 40, 0xffffff, "ZOOM: -/+");
	mlx_string_put(p.mlx, p.window, 1500,\
	60, 0xffffff, "ROTATE: X: 4/6 Y: 2/8 Z: 1/9");
	mlx_string_put(p.mlx, p.window, 1500, 80, 0xffffff, "EXIT: ESC");
	mlx_string_put(p.mlx, p.window, 1500, 100, 0xffffff, "COLOR SET: Z-C");
	mlx_string_put(p.mlx, p.window, 1500, 120, 0xffffff, "ISOMETRIC: I");
	mlx_string_put(p.mlx, p.window, 1500, 140, 0xffffff, "FRONTAL: O");
}

int		main(int argc, char **argv)
{
	t_trasform_params	params;
	t_map				map;

	if (argc != 2)
		read_map_error();
	map = map_scan(argv[1]);
	map.color_set = 0x0;
	params = transform_params_init(map);
	mlx_put_image_to_window(map.mlx, map.window, map.img, 0, 0);
	draw(map, params);
	print_menu(map);
	push_control(&map, &params);
	mlx_loop(map.mlx);
}
