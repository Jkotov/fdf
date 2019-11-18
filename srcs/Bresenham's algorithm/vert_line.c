/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 05:18:02 by epainter          #+#    #+#             */
/*   Updated: 2019/11/18 05:18:32 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vert_line(t_pixel pixel_1st,\
	t_pixel pixel_end, void *mlx_ptr, void *win_ptr)
{
	double		*color;
	double		*delta_color;

	delta_color = color_delta(pixel_1st, pixel_end);
	color = color_from_int_to_arr(pixel_1st.color);
	while (pixel_1st.y != pixel_end.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixel_1st.x,\
		pixel_1st.y, color_inc(&color, delta_color));
		pixel_1st.y < pixel_end.y ? pixel_1st.y++ : pixel_1st.y--;
	}
	free_color_and_delta(color, delta_color);
}
