/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:42:10 by epainter          #+#    #+#             */
/*   Updated: 2019/11/24 14:52:48 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	move(t_pixel pixel, t_pixel shift)
{
	pixel.x += shift.x;
	pixel.y += shift.y;
	pixel.z += shift.z;
	return (pixel);
}
