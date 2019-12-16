/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:39:42 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/16 18:38:12 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONTROL_H
# define FDF_CONTROL_H

# include "fdf.h"

typedef struct	s_mouse
{
	int			press_l;
	int			press_r;
	int			x;
	int			y;
	int			x_pred;
	int			y_pred;
}				t_mouse;

typedef struct	s_control
{
	t_trasform_params	*p;
	t_map				*map;
	t_mouse				*mouse;
}				t_control;

void			keyboard_move(int key, t_control *p);
void			keyboard_rotate(int key, t_control *p);
void			key_zoom(int key, t_control *p);
int				push_key(int key, void *param);
int				push_mouse(int key, int x, int y, void *param);
int				repush_mouse(int key, int x, int y, void *param);
int				move_mouse(int x, int y, void *param);
void			keyboard_color(int key, t_control *p);
void			keyboard_projetion(int key, t_control *p);

#endif
