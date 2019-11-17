/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:17:54 by epainter          #+#    #+#             */
/*   Updated: 2019/11/17 23:23:30 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE_X 1366
# define WIN_SIZE_Y 768
# include "mlx.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>

typedef	struct	s_pixel
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;
}				t_pixel;

void			line(t_pixel pixel_start, t_pixel pixel_end,\
	void *mlx_ptr, void *win_ptr);
int				ft_abs(int n);
double			percentage(double start, double end, double cur);
uint32_t		color_from_arr_to_int(double const *src_color);
double			*color_from_int_to_arr(uint32_t src_color);
double			*color_delta(t_pixel pixel_1st, t_pixel pixel_end);
double			*color_plus_delta_color(double *color, double const *delta);

#endif
