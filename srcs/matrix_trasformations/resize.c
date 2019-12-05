/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:28:02 by epainter          #+#    #+#             */
/*   Updated: 2019/12/05 14:15:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	resize(t_pixel pixel, uint32_t size)
{
	pixel.x *= size;
	pixel.y *= size;
	pixel.z *= size;
	return (pixel);
}
