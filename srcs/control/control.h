/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:39:42 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/05 14:15:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONTROL_H
# define FDF_CONTROL_H

# include "fdf.h"

void		keyboard_move(int key, t_trasform_params *p);
void		keyboard_rotate(int key, t_trasform_params *p);
void		keyboard_zoom(int key, t_trasform_params *p);
int			push_key(int key, void *param);
int			push_mouse(int key, void *param);

#endif
