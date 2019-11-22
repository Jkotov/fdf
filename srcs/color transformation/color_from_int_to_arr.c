/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_from_int_to_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:00:42 by epainter          #+#    #+#             */
/*   Updated: 2019/11/18 09:42:37 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		*color_from_int_to_arr(uint32_t src_color)
{
	double	*res;

	res = (double*)malloc(sizeof(double) * 4);
	res[3] = (double)(src_color & (uint32_t)0xff);
	res[2] = (double)((src_color & (uint32_t)0xff00) >> (uint32_t)8);
	res[1] = (double)((src_color & (uint32_t)0xff0000) >> (uint32_t)16);
	res[0] = (double)((src_color & (uint32_t)0xff000000) >> (uint32_t)24);
	return (res);
}
