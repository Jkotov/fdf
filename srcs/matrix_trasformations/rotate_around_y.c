/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:26:14 by epainter          #+#    #+#             */
/*   Updated: 2019/12/05 14:15:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel	rotate_around_y(t_pixel pixel, double angle)
{
	double tmp_x;

	tmp_x = (double)pixel.x;
	pixel.x = (int)(tmp_x * cos(angle) + (double)pixel.z * sin(angle));
	pixel.z = (int)(-tmp_x * sin(angle) + (double)pixel.z * cos(angle));
	return (pixel);
}
