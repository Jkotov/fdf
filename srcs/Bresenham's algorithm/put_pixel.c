/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:49:19 by epainter          #+#    #+#             */
/*   Updated: 2019/12/14 16:27:03 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_pixel pixel, int **img_data,
	double **color, double *d_color)
{
	if (pixel.x >= 0 && pixel.x < WIN_SIZE_X\
	&& pixel.y >= 0 && pixel.y <= WIN_SIZE_Y)
	{
		if ((uint8_t)color[0][0] != 0xff)
			(*img_data)[pixel.y * WIN_SIZE_X\
			+ pixel.x] = color_inc(color, d_color);
		if ((uint8_t)color[0][0] == 0xff)
			(*img_data)[pixel.y * WIN_SIZE_X + pixel.x] = 0x00ffffff;
	}
}
