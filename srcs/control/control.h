/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:39:42 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/13 15:03:36 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONTROL_H
# define FDF_CONTROL_H

# include "fdf.h"

typedef struct	s_control
{
	t_trasform_params	*p;
	t_map				*map;
}				t_control;

void		keyboard_move(int key, t_control *p);
void		keyboard_rotate(int key, t_control *p);
void		keyboard_zoom(int key, t_control *p);
int			push_key(int key, void *param);
int			push_mouse(int key, t_control *p);
void		keyboard_color(int key, t_control *p);

#endif
