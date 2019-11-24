/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:02:37 by epainter          #+#    #+#             */
/*   Updated: 2019/11/24 18:20:07 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel rotate_around_x(t_pixel pixel, double angle)
{
	double tmp_y;

	tmp_y = (double)pixel.y;
	pixel.y = (uint32_t)(tmp_y * cos(angle) - (double)pixel.z * sin(angle));
	pixel.z = (uint32_t)(tmp_y * sin(angle) + (double)pixel.z * cos(angle));
	return (pixel);
}
