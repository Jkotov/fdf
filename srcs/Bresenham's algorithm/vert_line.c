/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 05:18:02 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vert_line(t_pixel pixel_1st,\
	t_pixel pixel_end, int *img_data)
{
	double		*color;
	double		*delta_color;

	delta_color = color_delta(pixel_1st, pixel_end);
	color = color_from_int_to_arr(pixel_1st.color);
	while (pixel_1st.y != pixel_end.y)
	{
		put_pixel(pixel_1st, &img_data, &color, delta_color);
		pixel_1st.y < pixel_end.y ? pixel_1st.y++ : pixel_1st.y--;
	}
	free_color_and_delta(color, delta_color);
}
