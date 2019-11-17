/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:13:58 by epainter          #+#    #+#             */
/*   Updated: 2019/11/17 23:26:03 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line(t_pixel pixel_1st, t_pixel pixel_end, void *mlx_ptr, void *win_ptr)
{
	int			delta_x;
	int			error;
	int			delta_err;
	double		*color;
	double		*delta_color;


	delta_color = color_delta(pixel_1st, pixel_end);
	delta_x = ft_abs((int)pixel_end.x - (int)pixel_1st.x);
	color = color_from_int_to_arr(pixel_1st.color);
	error = 0;
	delta_err = ft_abs((int)pixel_end.y - (int)pixel_1st.y);
	while (pixel_1st.x != pixel_end.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixel_1st.x, pixel_1st.y, color_from_arr_to_int(color));
		color = color_plus_delta_color(color, delta_color);
		error = error + delta_err;
		while (2 * error >= delta_x)
		{
			pixel_1st.y < pixel_end.y ? pixel_1st.y++ : pixel_1st.y--;
			error = error - delta_x;
			if (2 * error >= delta_x)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, pixel_1st.x, pixel_1st.y, color_from_arr_to_int(color));
				color = color_plus_delta_color(color, delta_color);
			}
		}
		pixel_1st.x < pixel_end.x ? pixel_1st.x++ : pixel_1st.x--;
	}
	while (pixel_1st.y != pixel_end.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixel_1st.x, pixel_1st.y, color_from_arr_to_int(color));
		color = color_plus_delta_color(color, delta_color);
		pixel_1st.y < pixel_end.y ? pixel_1st.y++ : pixel_1st.y--;
	}
	free(color);
	free(delta_color);
}
