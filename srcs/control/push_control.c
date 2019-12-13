/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:44:04 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/13 15:21:09 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	push_control(t_map *map, t_trasform_params *p)
{
	t_control *control;

	control = malloc(sizeof(t_control));
	control->map = map;
	control->p = p;
	mlx_hook(map->window, 2, 0, push_key, control);
//	mlx_hook(p->window, 4, 0, push_mouse, p);
}