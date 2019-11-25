/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 01:01:06 by epainter          #+#    #+#             */
/*   Updated: 2019/11/25 01:02:46 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_pixel	rotate_around_z(t_pixel pixel, double angle)
{
	double tmp_x;

	tmp_x = (double)pixel.x;
	pixel.x = (int)(tmp_x * cos(angle) - (double)pixel.y * sin(angle));
	pixel.y = (int)(tmp_x * sin(angle) + (double)pixel.y * cos(angle));
	return (pixel);
}
