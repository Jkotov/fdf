/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:53:29 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/15 15:24:38 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		keyboard_move(int key, t_control *p)
{
	mlx_clear_window(p->map->mlx, p->map->window);
	if (key == 124)
	{
		p->p->shift.x = p->p->shift.x + 10;
		p->p->shift.z = p->p->shift.z + 10;
	}
	if (key == 123)
	{
		p->p->shift.x = p->p->shift.x - 10;
		p->p->shift.z = p->p->shift.z - 10;
	}
	if (key == 126)
	{
		p->p->shift.y = p->p->shift.y - 10;
		p->p->shift.z = p->p->shift.z + 10;
	}
	if (key == 125)
	{
		p->p->shift.y = p->p->shift.y + 10;
		p->p->shift.z = p->p->shift.z - 10;
	}
	draw(*p->map, *p->p);
	print_menu(*p->map);
}

void		keyboard_rotate(int key, t_control *p)
{
	mlx_clear_window(p->map->mlx, p->map->window);
	if (key == 86)
		p->p->angle_x = p->p->angle_x - M_PI / 36;
	if (key == 88)
		p->p->angle_x = p->p->angle_x + M_PI / 36;
	if (key == 84)
		p->p->angle_y = p->p->angle_y - M_PI / 36;
	if (key == 91)
		p->p->angle_y = p->p->angle_y + M_PI / 36;
	if (key == 83)
		p->p->angle_z = p->p->angle_z - M_PI / 36;
	if (key == 92)
		p->p->angle_z = p->p->angle_z + M_PI / 36;
	draw(*(p->map), *(p->p));
	print_menu(*(p->map));
}

void		keyboard_zoom(int key, t_control *p)
{
	mlx_clear_window(p->map->mlx, p->map->window);
	if (key == 78)
		p->p->size--;
	if (key == 69)
		p->p->size++;
	draw(*(p->map), *(p->p));
	print_menu(*(p->map));
}


int			push_key(int key, void *param)
{
	t_control *p;

	p = (t_control *)param;
	if (key == 53)
		exit(0);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		keyboard_move(key, p);
	else if (key == 86 || key == 88 || key == 84 || key == 91 ||
	key == 83 || key == 92)
		keyboard_rotate(key, p);
	else if (key == 78 || key == 69)
		keyboard_zoom(key, p);
	if (key > 5 && key < 9)
		keyboard_color(key, p);
	return (0);
}
