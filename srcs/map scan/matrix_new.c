/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 03:48:32 by epainter          #+#    #+#             */
/*   Updated: 2019/11/28 20:36:51 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_pixel	**matrix_new(int x, int y)
{
	t_pixel	**matrix;

	matrix = (t_pixel**)malloc(sizeof(t_pixel*) * y);
	if (matrix == NULL)
		read_map_error();
	y--;
	while (y + 1 != 0)
	{
		matrix[y] = (t_pixel*)malloc(sizeof(t_pixel) * x);
		if (matrix[y] == NULL)
			read_map_error();
		y--;
	}
	return (matrix);
}
