/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_trasforms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:55:33 by epainter          #+#    #+#             */
/*   Updated: 2019/12/18 16:18:32 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		all_trasforms(t_pixel pixel, t_trasform_params params)
{
	t_pixel	shift_to_center;

	shift_to_center.x = -params.center.x;
	shift_to_center.y = -params.center.y;
	shift_to_center.z = -params.center.z;
	pixel = move(pixel, shift_to_center);
	params.center = resize(params.center, params.size);
	pixel = resize(pixel, params.size);
	pixel = rotate_around_x(pixel, params.angle_x);
	pixel = rotate_around_y(pixel, params.angle_y);
	pixel = rotate_around_z(pixel, params.angle_z);
	pixel = move(pixel, params.shift);
	pixel = move(pixel, params.center);
	pixel = central_projection(pixel, params.shift);
	return (pixel);
}
