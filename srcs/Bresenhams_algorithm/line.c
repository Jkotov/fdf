/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:13:58 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line(t_pixel pxl_1st, t_pixel pxl_end, int *img_data)
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
		put_pixel(pxl_1st, &img_data, &color, d_color);
		error = error + delta_err;
		while (2 * error >= delta_x)
		{
			pxl_1st.y < pxl_end.y ? pxl_1st.y++ : pxl_1st.y--;
			if (2 * (error -= delta_x) >= delta_x)
				put_pixel(pxl_1st, &img_data, &color, d_color);
		}
		pxl_1st.x < pxl_end.x ? pxl_1st.x++ : pxl_1st.x--;
	}
	vert_line(pxl_1st, pxl_end, img_data);
	free_color_and_delta(color, d_color);
}
