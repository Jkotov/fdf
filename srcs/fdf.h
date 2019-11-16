/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:17:54 by epainter          #+#    #+#             */
/*   Updated: 2019/11/01 16:15:39 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SIZE_X 300
# define SIZE_Y 400
# include "mlx.h"
# include <math.h>

void line(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr);

#endif
