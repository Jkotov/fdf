/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:02:37 by epainter          #+#    #+#             */
/*   Updated: 2019/12/05 14:15:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel	rotate_around_x(t_pixel pixel, double angle)
{
	double tmp_y;

	tmp_y = (double)pixel.y;
	pixel.y = (int)(tmp_y * cos(angle) - (double)pixel.z * sin(angle));
	pixel.z = (int)(tmp_y * sin(angle) + (double)pixel.z * cos(angle));
	return (pixel);
}
