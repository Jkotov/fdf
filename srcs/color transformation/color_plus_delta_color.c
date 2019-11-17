/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_plus_delta_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:23:35 by epainter          #+#    #+#             */
/*   Updated: 2019/11/17 23:23:35 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*color_plus_delta_color(double *color, double const *delta)
{
	color[0] += delta[0];
	color[1] += delta[1];
	color[2] += delta[2];
	color[3] += delta[3];

	return (color);
}