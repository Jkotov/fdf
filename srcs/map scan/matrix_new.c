/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 03:48:32 by epainter          #+#    #+#             */
/*   Updated: 2019/11/25 04:20:21 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_pixel	**matrix_new(int x, int y)
{
	int		i;
	t_pixel	**matrix;

	i = 0;
	matrix = malloc(sizeof(t_pixel*) * y);
	if (matrix == NULL)
		read_map_error();
	ft_bzero(matrix, y * sizeof(t_pixel*));
	while (y + 1 != 0)
	{
		matrix[y] = malloc(sizeof(t_pixel) * x);
		if (matrix[y] == NULL)
			read_map_error();
		ft_bzero(matrix[y], sizeof(t_pixel) * x);
		y--;
	}
	return (matrix);
}
