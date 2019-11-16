/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:13:58 by epainter          #+#    #+#             */
/*   Updated: 2019/11/16 21:52:03 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	static	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

void		line(t_pixel pixel_Start, t_pixel pixel_End, void *mlx_ptr, void *win_ptr)
{
	int deltax = ft_abs(pixel_End.x - pixel_Start.x);
	int deltay = ft_abs(pixel_End.y - pixel_Start.y);
	int error = 0;
	int deltaerr = deltay;
	int diry;
	diry = pixel_End.y - pixel_Start.y > 0 ? 1 : -1;
	while (pixel_Start.x != pixel_End.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixel_Start.x, pixel_Start.y, pixel_Start.color);
		error = error + deltaerr;
		while (2 * error >= deltax)
		{
			pixel_Start.y = pixel_Start.y + diry;
			error = error - deltax;
			if (2 * error >= deltax)
				mlx_pixel_put(mlx_ptr, win_ptr, pixel_Start.x, pixel_Start.y, pixel_Start.color);
		}
		pixel_Start.x < pixel_End.x ? pixel_Start.x++ : pixel_Start.x--;
	}
	while (pixel_Start.y != pixel_End.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixel_Start.x, pixel_Start.y, pixel_Start.color);
		pixel_Start.y += diry;
	}
}