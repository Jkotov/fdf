/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:06 by epainter          #+#    #+#             */
/*   Updated: 2019/12/14 19:42:33 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map map, t_trasform_params p)
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
			line(all_trasforms(map.map[i][j], p),\
			all_trasforms(map.map[i][j + 1], p), map.img_data);
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
