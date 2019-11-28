/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:13:58 by epainter          #+#    #+#             */
/*   Updated: 2019/11/18 09:42:37 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line(t_pixel pxl_1st, t_pixel pxl_end, void *mlx_ptr, void *win_ptr)
{
	int			delta_x;
	int			error;
	int			delta_err;
	double		*color;
	double		*d_color;

	d_color = color_delta(pxl_1st, pxl_end);
	color = color_from_int_to_arr(pxl_1st.color);
	error = init_start_values(&delta_x, &delta_err, pxl_1st, pxl_end);
	while (pxl_1st.x != pxl_end.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pxl_1st.x,\
		pxl_1st.y, color_inc(&color, d_color));
		error = error + delta_err;
		while (2 * error >= delta_x)
		{
			pxl_1st.y < pxl_end.y ? pxl_1st.y++ : pxl_1st.y--;
			if (2 * (error -= delta_x) >= delta_x)
				mlx_pixel_put(mlx_ptr, win_ptr, pxl_1st.x,\
				pxl_1st.y, color_inc(&color, d_color));
		}
		pxl_1st.x < pxl_end.x ? pxl_1st.x++ : pxl_1st.x--;
	}
	vert_line(pxl_1st, pxl_end, mlx_ptr, win_ptr);
	free_color_and_delta(color, d_color);
}
