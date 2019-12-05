/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:53:29 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/05 13:38:08 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		keyboard_move(int key, t_trasform_params *p)
{
	mlx_clear_window(p->mlx, p->window);
	if (key == 124)
	{
		p->shift.x = p->shift.x + 10;
		p->shift.z = p->shift.z + 10;
	}
	if (key == 123)
	{
		p->shift.x = p->shift.x - 10;
		p->shift.z = p->shift.z - 10;
	}
	if (key == 126)
	{
		p->shift.y = p->shift.y - 10;
		p->shift.z = p->shift.z + 10;
	}
	if (key == 125)
	{
		p->shift.y = p->shift.y + 10;
		p->shift.z = p->shift.z - 10;
	}
	draw(*p);
	print_menu(*p);
}

void		keyboard_rotate(int key, t_trasform_params *p)
{
	mlx_clear_window(p->mlx, p->window);
	if (key == 86)
		p->angle_x = p->angle_x - M_PI / 36;
	if (key == 88)
		p->angle_x = p->angle_x + M_PI / 36;
	if (key == 84)
		p->angle_y = p->angle_y - M_PI / 36;
	if (key == 91)
		p->angle_y = p->angle_y + M_PI / 36;
	if (key == 83)
		p->angle_z = p->angle_z - M_PI / 36;
	if (key == 92)
		p->angle_z = p->angle_z + M_PI / 36;
	draw(*p);
	print_menu(*p);
}

void		keyboard_zoom(int key, t_trasform_params *p)
{
	mlx_clear_window(p->mlx, p->window);
	if (key == 78)
		p->size--;
	if (key == 69)
		p->size++;
	draw(*p);
	print_menu(*p);
}

int			push_key(int key, void *param)
{
	t_trasform_params *p;

	p = (t_trasform_params *)param;
	if (key == 53)
		exit(0);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		keyboard_move(key, p);
	else if (key == 86 || key == 88 || key == 84 || key == 91 ||
	key == 83 || key == 92)
		keyboard_rotate(key, p);
	else if (key == 78 || key == 69)
		keyboard_zoom(key, p);
	return (0);
}
