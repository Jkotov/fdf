/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:13:58 by epainter          #+#    #+#             */
/*   Updated: 2019/11/16 15:58:18 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int 	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

void	line(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr)
{
	int deltax = ft_abs(x1 - x0);
	int deltay = ft_abs(y1 - y0);
	int error = 0;
	int deltaerr = deltay;
	int y = y0;
	int diry = y1 - y0;
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	while (x0 < x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y, 0xa9203e);
		error = error + deltaerr;
		while (2 * error >= deltax)
		{
			y = y + diry;
			error = error - deltax;
			if (2 * error >= deltax)
				mlx_pixel_put(mlx_ptr, win_ptr, x0, y, 0xa9203e);
		}
		x0++;
	}
}