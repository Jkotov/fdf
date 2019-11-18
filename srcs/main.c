/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/11/18 04:17:24 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

int main(void)
{
	void *mlx_ptr;
	void *window_ptr;
	t_pixel pixel_start;
	t_pixel pixel_end;

	pixel_start.x = WIN_SIZE_X / 2;
	pixel_start.y = WIN_SIZE_Y / 2;
	pixel_start.color = 0x00008000;
	pixel_end.color = 0x008b4513;
	pixel_end.x = 0;
	pixel_end.y = 0;
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, "fdf_test_screen");
	while (pixel_end.x++ < WIN_SIZE_X)
		line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = WIN_SIZE_X / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = WIN_SIZE_X;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.y = WIN_SIZE_Y / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.y = WIN_SIZE_Y;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = WIN_SIZE_X / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.x = 0;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	pixel_end.y = WIN_SIZE_Y / 2;
	line(pixel_start, pixel_end, mlx_ptr, window_ptr);
	mlx_pixel_put(mlx_ptr, window_ptr, 1, 1, 0xffff);
	mlx_loop(mlx_ptr);
}