/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:44:04 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/05 14:15:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	push_control(t_trasform_params *p)
{
	mlx_hook(p->window, 2, 0, push_key, p);
//	mlx_hook(p->window, 4, 0, push_mouse, p);
}