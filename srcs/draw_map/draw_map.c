/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:06 by epainter          #+#    #+#             */
/*   Updated: 2019/12/14 23:27:52 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	uint32_t	color_set(int z, t_map map)
{
	double		*color;
	uint32_t	res;

	color = color_from_int_to_arr(map.color_set);
	color[0] *= percentage(map.min_z, map.max_z, z);
	color[1] *= percentage(map.min_z, map.max_z, z);
	color[2] *= percentage(map.min_z, map.max_z, z);
	color[3] *= percentage(map.min_z, map.max_z, z);
	res = color_from_arr_to_int(color);
	res = 0xffffff - res;
	free(color);
	return (res);
}

void				draw(t_map map, t_trasform_params p)
{
	int i;
	int j;

	i = -1;
	mlx_clear_window(map.mlx, map.window);
	ft_bzero(map.img_data, WIN_SIZE_X * WIN_SIZE_Y * 4);
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j].is_exist_next == 1)
		{
			map.map[i][j].color = color_set(map.map[i][j].z, map);
			map.map[i][j + 1].color  = color_set(map.map[i][j + 1].z, map);
			line(all_trasforms(map.map[i][j], p), \
            all_trasforms(map.map[i][j + 1], p), map.img_data);
		}
		if (map.map[i + 1] == NULL)
			break ;
		j = -1;
		while (j++ > INT32_MIN)
		{
			line(all_trasforms(map.map[i][j], p),\
			all_trasforms(map.map[i + 1][j], p), map.img_data);
			if (!(map.map[i][j].is_exist_next\
			&& map.map[i + 1][j].is_exist_next))
				break ;
		}
	}
	mlx_put_image_to_window(map.mlx, map.window, map.img, 0, 0);
}
