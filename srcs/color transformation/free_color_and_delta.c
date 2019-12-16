/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_color_and_delta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:11:08 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_color_and_delta(double *color, double *delta)
{
	free(color);
	free(delta);
	color = NULL;
	delta = NULL;
}
