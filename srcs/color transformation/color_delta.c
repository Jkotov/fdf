/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_delta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:22:04 by epainter          #+#    #+#             */
/*   Updated: 2019/11/17 23:45:14 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*color_delta(t_pixel pixel_1st, t_pixel pixel_end)
{
	uint32_t	num_of_steps;
	uint32_t	delta_x;
	uint32_t	delta_y;
	double		*delta_color;
	double		*tmp;

	delta_x = (uint32_t)ft_abs((int)pixel_end.x - (int)pixel_1st.x);
	delta_y = (uint32_t)ft_abs((int)pixel_end.y - (int)pixel_1st.y);
	num_of_steps = (delta_x > delta_y ? delta_x : delta_y);
	delta_color = color_from_int_to_arr(pixel_end.color);
	tmp = color_from_int_to_arr(pixel_1st.color);
	delta_color[0] = (delta_color[0] - tmp[0]) / num_of_steps;
	delta_color[1] = (delta_color[1] - tmp[1]) / num_of_steps;
	delta_color[2] = (delta_color[2] - tmp[2]) / num_of_steps;
	delta_color[3] = (delta_color[3] - tmp[3]) / num_of_steps;
	free(tmp);
	return (delta_color);
}
