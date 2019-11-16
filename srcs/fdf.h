/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:17:54 by epainter          #+#    #+#             */
/*   Updated: 2019/11/16 18:44:46 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE_X 300
# define WIN_SIZE_Y 400
# include "mlx.h"
# include <math.h>

typedef	struct	s_pixel
{
	int x;
	int y;
	int color;
}				t_pixel;

void	line(t_pixel pixel_Start, t_pixel pixel_End, void *mlx_ptr, void *win_ptr);

#endif
