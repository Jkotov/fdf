/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:34:11 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/18 16:34:41 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	central_projection(t_pixel pixel, t_pixel shift)
{
	int z;

	shift.x = WIN_SIZE_X / 2;
	shift.y = WIN_SIZE_Y / 2;
	shift.z = Z_MAX;
	z = 900;
	if (pixel.z != shift.z)
	{
		pixel.x = ((z - shift.z) * (pixel.x - shift.x)) / (pixel.z - shift.z) + shift.x;
		pixel.y = ((z - shift.z) * (pixel.y - shift.y)) / (pixel.z - shift.z) + shift.y;
	}
	return (pixel);
}
