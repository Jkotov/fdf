/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 05:42:49 by epainter          #+#    #+#             */
/*   Updated: 2019/11/18 05:50:26 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	init_start_values(int *delta_x, int *delta_err,\
	t_pixel pxl_1st, t_pixel pxl_end)
{
	*delta_x = ft_abs((int)pxl_end.x - (int)pxl_1st.x);
	*delta_err = ft_abs((int)pxl_end.y - (int)pxl_1st.y);
	return (0);
}
