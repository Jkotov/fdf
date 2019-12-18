/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_inc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 03:52:10 by epainter          #+#    #+#             */
/*   Updated: 2019/12/18 13:24:48 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_inc(double **color, double const *delta)
{
	int res;

	res = color_from_arr_to_int(*color);
	*color = color_plus_delta_color(*color, delta);
	return (res);
}
