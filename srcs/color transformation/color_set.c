/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:16 by epainter          #+#    #+#             */
/*   Updated: 2019/12/15 15:57:16 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	color_set(t_pixel pixel, t_map map)
{
	double		*color;
	uint32_t	res;

	if (pixel.color != 0xff000000)
		return (pixel.color);
	color = color_from_int_to_arr(map.color_set);
	color[0] *= percentage(map.min_z, map.max_z, pixel.z);
	color[1] *= percentage(map.min_z, map.max_z, pixel.z);
	color[2] *= percentage(map.min_z, map.max_z, pixel.z);
	color[3] *= percentage(map.min_z, map.max_z, pixel.z);
	res = color_from_arr_to_int(color);
	res = 0xffffff - res;
	free(color);
	return (res);
}
