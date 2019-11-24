/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_trasforms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:55:33 by epainter          #+#    #+#             */
/*   Updated: 2019/11/24 17:52:42 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		all_trasforms(t_pixel pixel, t_trasform_params params)
{
	pixel = resize(pixel, params.size);
	pixel = move(pixel, params.shift);
	pixel = rotate_around_x(pixel, params.angle_x);
	pixel = rotate_around_y(pixel, params.angle_y);
	pixel = rotate_around_z(pixel, params.angle_z);
	return (pixel);
}