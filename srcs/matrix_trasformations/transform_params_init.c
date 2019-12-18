/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_params_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:09:20 by epainter          #+#    #+#             */
/*   Updated: 2019/12/14 20:15:14 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trasform_params	transform_params_init(t_map map)
{
	t_trasform_params	params;

	params.shift.x = SHIFTX;
	params.shift.y = SHIFTY;
	params.shift.z = SHIFTZ;
	params.size = SIZE;
	params.angle_x = 0;
	params.angle_y = 0;
	params.angle_z = 0;
	params.center = find_center(map);
	params.is_central_projection = 0;
	return (params);
}
