/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:08:43 by epainter          #+#    #+#             */
/*   Updated: 2019/11/16 15:30:51 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int main(void)
{
	void *mlx_ptr;
	void *window_ptr;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, "fdf_test_screen");
	line(1, 50, 100, 0, mlx_ptr, window_ptr);
	mlx_pixel_put(mlx_ptr, window_ptr, 1, 1, 0xa9203e);
	mlx_loop(mlx_ptr);
}