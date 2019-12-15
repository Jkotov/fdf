/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:06 by epainter          #+#    #+#             */
/*   Updated: 2019/12/15 22:01:30 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		draw_x_lines(t_map map, t_trasform_params p, int i)
{
	int			j;
	t_pixel		tmp_pixel[2];

	j = -1;
	while (map.map[i][++j].is_exist_next == 1)
	{
		tmp_pixel[0] = all_trasforms(map.map[i][j], p);
		tmp_pixel[1] = all_trasforms(map.map[i][j + 1], p);
		tmp_pixel[0].color = color_set(map.map[i][j], map);
		tmp_pixel[1].color = color_set(map.map[i][j + 1], map);
		line(tmp_pixel[0], tmp_pixel[1], map.img_data);
	}
}

static	void		draw_y_lines(t_map map, t_trasform_params p, int i)
{
	int			j;
	t_pixel		tmp_pixel[2];

	j = -1;
	while (j++ > INT32_MIN)
	{
		tmp_pixel[0] = all_trasforms(map.map[i][j], p);
		tmp_pixel[1] = all_trasforms(map.map[i + 1][j], p);
		tmp_pixel[0].color = color_set(map.map[i][j], map);
		tmp_pixel[1].color = color_set(map.map[i + 1][j], map);
		line(tmp_pixel[0], tmp_pixel[1], map.img_data);
		if (!(map.map[i][j].is_exist_next\
			&& map.map[i + 1][j].is_exist_next))
			break ;
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
	print_menu(map);
}
