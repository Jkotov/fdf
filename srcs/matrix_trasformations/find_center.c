/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:55:10 by epainter          #+#    #+#             */
/*   Updated: 2019/12/14 18:58:48 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel			find_center(t_map map)
{
	t_pixel	pixel;
	int		i;

	i = 0;
	while (map.map[i])
		i++;
	pixel.y = i / 2;
	while (map.map[0][i].is_exist_next == 1)
		i++;
	pixel.x = i / 2;
	pixel.z = 0;
	return (pixel);
}
