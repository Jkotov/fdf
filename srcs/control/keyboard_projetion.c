/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_projetion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:32:14 by epainter          #+#    #+#             */
/*   Updated: 2019/12/15 18:37:25 by epainter         ###   ########.fr       */
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
	draw(*(p->map), *(p->p));
}
