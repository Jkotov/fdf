/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:17:54 by epainter          #+#    #+#             */
/*   Updated: 2019/12/05 15:08:35 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# include "mlx.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
#define SIZE 30
#define SHIFTX 200
#define SHIFTY 200
#define SHIFTZ 0
#define ANGLEX 10

typedef	struct	s_pixel
{
	int			x;
	int			y;
	uint32_t	color;
	int			z;
	char		is_exist;
}				t_pixel;

typedef	struct	s_trasform_params
{
	t_pixel		**map;
	uint32_t	size;
	t_pixel		shift;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	void 		*window;
	void		*mlx;
	void		*img;
	int			*img_data;
}				t_trasform_params;

void			draw(t_trasform_params params);
void			print_menu(t_trasform_params p);
void 			push_control(t_trasform_params *p);
t_pixel			**matrix_new(int x, int y);
t_pixel			rotate_around_x(t_pixel pixel, double angle);
t_pixel			rotate_around_y(t_pixel pixel, double angle);
t_pixel			rotate_around_z(t_pixel pixel, double angle);
t_pixel			all_trasforms(t_pixel pixel, t_trasform_params params);
t_pixel			move(t_pixel pixel, t_pixel shift);
t_pixel			resize(t_pixel pixel, uint32_t size);
void			line(t_pixel pxl_start, t_pixel pxl_end, int *img_data);
int				ft_abs(int n);
double			percentage(double start, double end, double cur);
uint32_t		color_from_arr_to_int(double const *src_color);
double			*color_from_int_to_arr(uint32_t src_color);
double			*color_delta(t_pixel pixel_1st, t_pixel pixel_end);
double			*color_plus_delta_color(double *color, double const *delta);
int				color_inc(double **color, double const *delta);
void			free_color_and_delta(double *color, double *delta);
void			vert_line(t_pixel pixel_1st, t_pixel pixel_end,\
	int *img_data);
int				init_start_values(int *delta_x, int *delta_err,\
	t_pixel pxl_1st, t_pixel pxl_end);
void			read_map_error(void);
t_pixel			**map_scan(char const *file_name);
#endif