/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/11/16 21:35:25 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

int main(void)
{
	void *mlx_ptr;
	void *window_ptr;
	t_pixel pixel_Start;
	t_pixel pixel_End;

	pixel_Start.x = WIN_SIZE_X / 2;
	pixel_Start.y = WIN_SIZE_Y / 2;
	pixel_Start.color = 0xffffff;
	pixel_End.x = 0;
	pixel_End.y = 0;
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, "fdf_test_screen");
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.x = WIN_SIZE_X / 2;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.x = WIN_SIZE_X;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.y = WIN_SIZE_Y / 2;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.y = WIN_SIZE_Y;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.x = WIN_SIZE_X / 2;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.x = 0;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	pixel_End.y = WIN_SIZE_Y / 2;
	line(pixel_Start, pixel_End, mlx_ptr, window_ptr);
	mlx_pixel_put(mlx_ptr, window_ptr, 1, 1, 0xa9203e);
	mlx_loop(mlx_ptr);
}