/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_projetion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:32:14 by epainter          #+#    #+#             */
/*   Updated: 2019/12/18 17:56:07 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "control.h"

void	keyboard_projetion(int key, t_control *p)
{
	if (key == 31)
	{
		p->p->angle_x = 0;
		p->p->angle_y = 0;
		p->p->angle_z = 0;
	}
	if (key == 34)
	{
		p->p->angle_x = M_PI / 4;
		p->p->angle_y = 0.615;
		p->p->angle_z = -M_PI / 6;
	}
	if (key == 35)
	{
		if (p->p->is_central_projection)
			p->p->is_central_projection = 0;
		else
			p->p->is_central_projection = 1;
	}
	draw(*(p->map), *(p->p));
}
