/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_from_arr_to_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 22:59:34 by epainter          #+#    #+#             */
/*   Updated: 2019/11/17 22:59:34 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	color_from_arr_to_int(double const *src_color)
{
	uint32_t	res;

	res = (uint32_t)src_color[0] << (uint32_t)24;
	res += (uint32_t)src_color[1] << (uint32_t)16;
	res += (uint32_t)src_color[2] << (uint32_t)8;
	res += (uint32_t)src_color[3];
	return (res);
}