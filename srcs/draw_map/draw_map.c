/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:06 by epainter          #+#    #+#             */
/*   Updated: 2019/12/15 16:10:16 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		draw_x_lines(t_map map, t_trasform_params p, int i)
{
	uint32_t	tmp_color[2];
	int			j;

	j = -1;
	while (map.map[i][++j].is_exist_next == 1)
	{
		tmp_color[0] = map.map[i][j].color;
		tmp_color[1] = map.map[i][j + 1].color;
		map.map[i][j].color = color_set(map.map[i][j], map);
		map.map[i][j + 1].color = color_set(map.map[i][j + 1], map);
		line(all_trasforms(map.map[i][j], p),\
				all_trasforms(map.map[i][j + 1], p), map.img_data);
		map.map[i][j].color = tmp_color[0];
		map.map[i][j + 1].color = tmp_color[1];
	}
}

static	void		draw_y_lines(t_map map, t_trasform_params p, int i)
{
	int			j;
	uint32_t	tmp_color[2];

	j = -1;
	while (j++ > INT32_MIN)
	{
		tmp_color[0] = map.map[i][j].color;
		tmp_color[1] = map.map[i + 1][j].color;
		map.map[i][j].color = color_set(map.map[i][j], map);
		map.map[i + 1][j].color = color_set(map.map[i + 1][j], map);
		line(all_trasforms(map.map[i][j], p),\
			all_trasforms(map.map[i + 1][j], p), map.img_data);
		if (!(map.map[i][j].is_exist_next\
			&& map.map[i + 1][j].is_exist_next))
			break ;
		map.map[i][j].color = tmp_color[0];
		map.map[i + 1][j].color = tmp_color[1];
	}
}

void				draw(t_map map, t_trasform_params p)
{
	int			i;

	i = -1;
	mlx_clear_window(map.mlx, map.window);
	ft_bzero(map.img_data, WIN_SIZE_X * WIN_SIZE_Y * 4);
	while (map.map[++i])
	{
		draw_x_lines(map, p, i);
		if (map.map[i + 1] == NULL)
			break ;
		draw_y_lines(map, p, i);
	}
	mlx_put_image_to_window(map.mlx, map.window, map.img, 0, 0);
}
