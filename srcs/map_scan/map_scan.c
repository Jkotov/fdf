/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 02:50:46 by epainter          #+#    #+#             */
/*   Updated: 2019/12/18 13:25:48 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_scan.h"

t_map	map_scan(char const *file_name)
{
	char	*str;
	t_map	map;
	int		bit_depth;
	int		line;
	int		endian;

	bit_depth = 32;
	line = WIN_SIZE_X;
	endian = 0;
	str = read_map(file_name);
	map = string_to_tokens(str);
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx, WIN_SIZE_X, WIN_SIZE_Y, "fdf");
	map.img = mlx_new_image(map.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	map.img_data = (int*)mlx_get_data_addr(map.img, &bit_depth, &line, &endian);
	return (map);
}
