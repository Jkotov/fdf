/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:50:15 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/16 18:36:25 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int			push_mouse(int key, int x, int y, void *param)
{
	t_control *p;

	(void)x;
	(void)y;
	p = (t_control *)param;
	if (key == 4 || key == 5)
		key_zoom(key, p);
	if (key == 1)
		p->mouse->press_l = 1;
	if (key == 2)
		p->mouse->press_r = 1;
	return (0);
}

int			repush_mouse(int key, int x, int y, void *param)
{
	t_control *p;

	(void)x;
	(void)y;
	(void)key;
	p = (t_control *)param;
	p->mouse->press_l = 0;
	p->mouse->press_r = 0;
	return (0);
}

int			move_mouse(int x, int y, void *param)
{
	t_control *p;

	p = (t_control *)param;
	p->mouse->x_pred = p->mouse->x;
	p->mouse->y_pred = p->mouse->y;
	p->mouse->x = x;
	p->mouse->y = y;
	if (p->mouse->press_l == 1)
	{
		p->p->shift.x = p->p->shift.x + (x - p->mouse->x_pred);
		p->p->shift.y = p->p->shift.y + (y - p->mouse->y_pred);
		draw(*p->map, *p->p);
	}
	if (p->mouse->press_r == 1)
	{
		p->p->angle_x = p->p->angle_x + ((x - p->mouse->x_pred) * M_PI / 360);
		p->p->angle_y = p->p->angle_y + ((y - p->mouse->y_pred) * M_PI / 360);
		draw(*p->map, *p->p);
	}
	return (0);
}
