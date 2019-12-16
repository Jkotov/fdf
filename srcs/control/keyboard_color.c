/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:28:02 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 17:58:02 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "control.h"

void		keyboard_color(int key, t_control *p)
{
	mlx_clear_window(p->map->mlx, p->map->window);
	if (key == 6)
	{
		if ((uint32_t)p->map->color_set & (uint32_t)0xff0000)
			p->map->color_set -= (uint32_t)0xff0000;
		else
			p->map->color_set += (uint32_t)0xff0000;
	}
	if (key == 7)
	{
		if ((uint32_t)p->map->color_set & (uint32_t)0xff00)
			p->map->color_set -= (uint32_t)0x00ff00;
		else
			p->map->color_set += (uint32_t)0x00ff00;
	}
	if (key == 8)
	{
		if ((uint32_t)p->map->color_set & (uint32_t)0xff)
			p->map->color_set -= (uint32_t)0x0000ff;
		else
			p->map->color_set += (uint32_t)0x0000ff;
	}
	draw(*(p->map), *(p->p));
}
