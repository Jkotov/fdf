/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:16:06 by epainter          #+#    #+#             */
/*   Updated: 2019/12/18 16:46:22 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int8_t		is_in_window(t_pixel pixel)
{
	if (pixel.x <= WIN_SIZE_X && pixel.y <= WIN_SIZE_Y\
		&& pixel.x >= 0 && pixel.y >= 0)
		return (1);
	return (0);
}

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
		if ((is_in_window(tmp_pixel[0]) || is_in_window(tmp_pixel[1]))
		&& tmp_pixel[0].z <= Z_MAX && tmp_pixel[1].z <= Z_MAX)
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
		if ((is_in_window(tmp_pixel[0]) || is_in_window(tmp_pixel[1]))
			&& tmp_pixel[0].z <= Z_MAX && tmp_pixel[1].z <= Z_MAX)
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
