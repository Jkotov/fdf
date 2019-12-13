/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:06 by epainter          #+#    #+#             */
/*   Updated: 2019/12/13 15:26:13 by epainter         ###   ########.fr       */
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
	while (map.map[++i + 1])
	{
		j = -1;
		while (map.map[i][j++ + 1].is_exist_next == 1)
		{
			/*if (p.map[i][j].color == 0xff0000)
				p.map[i][j].color = 0x0000ff;
			if (p.map[i + 1][j].color == 0xff000000)
				p.map[i + 1][j].color = 0xff0000;*/
			if (map.map[i][j].is_exist_next == 1 && all_trasforms(map.map[i][j], p).x > 0 && all_trasforms(map.map[i][j], p).x < WIN_SIZE_X)
			{
				line(all_trasforms(map.map[i][j], p), all_trasforms(map.map[i + 1][j], p), map.img_data);
				if (!map.map[i][j + 1].z && map.map[i][j + 1].is_exist_next == 1)
					line(all_trasforms(map.map[i][j], p), all_trasforms(map.map[i][j + 1], p), map.img_data);
			}
		}
	}
	mlx_put_image_to_window(map.mlx, map.window, map.img, 0, 0);
}
