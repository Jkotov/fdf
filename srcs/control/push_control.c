/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:44:04 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/16 18:29:31 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	push_control(t_map *map, t_trasform_params *p)
{
	t_control	*control;
	t_mouse		*mouse;

	control = malloc(sizeof(t_control));
	control->map = map;
	control->p = p;
	mouse = malloc(sizeof(t_mouse));
	control->mouse = mouse;
	mlx_hook(map->window, 2, 0, push_key, control);
	mlx_hook(map->window, 4, 0, push_mouse, control);
	mlx_hook(map->window, 5, 0, repush_mouse, control);
	mlx_hook(map->window, 6, 0, move_mouse, control);
}
