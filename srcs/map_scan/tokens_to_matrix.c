/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:18:55 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static	int		*len_of_rows(char ***tokens)
{
	int		i[2];
	int		*imax;

	if (!(imax = (int*)malloc(sizeof(int) * 2)))
		read_map_error();
	i[0] = 0;
	imax[1] = 0;
	while (tokens[i[0]])
	{
		i[1] = 0;
		while (tokens[i[0]][i[1]])
			i[1]++;
		imax[1] = i[1] > imax[1] ? i[1] : imax[1];
		i[0]++;
	}
	imax[0] = i[0];
	return (imax);
}

static	t_pixel	pxl_params(char *token, int x, int y, t_map *map)
{
	t_pixel	res;

	res.y = y;
	res.x = x;
	res.z = ft_atoi(token);
	if (res.z < map->min_z)
		map->min_z = res.z;
	if (res.z > map->max_z)
		map->max_z = res.z;
	res.color = 0xff000000;
	if (ft_strchr(token, ','))
		res.color = ft_atoi_base(ft_strchr(token, 'x') + 1, 16);
	res.is_exist_next = 1;
	return (res);
}

static	void	free_token_and_imax(char ***tokens, int *imax)
{
	int i;
	int j;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		while (tokens[i][j])
		{
			free(tokens[i][j]);
			tokens[i][j] = NULL;
			j++;
		}
		i++;
	}
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
	free(imax);
}

t_map			tokens_to_matrix(char ***tokens)
{
	int		i[2];
	int		*imax;
	t_map	map;

	map.max_z = INT32_MIN;
	map.min_z = INT32_MAX;
	i[0] = -1;
	imax = len_of_rows(tokens);
	map.map = matrix_new(imax[1], imax[0]);
	while (++i[0] < imax[0])
	{
		i[1] = -1;
		while ((++i[1] <= imax[1]) && tokens[i[0]][i[1]])
			map.map[i[0]][i[1]] = pxl_params(tokens[i[0]][i[1]]\
			, i[1], i[0], &map);
		map.map[i[0]][i[1] - 1].is_exist_next = 0;
	}
	free_token_and_imax(tokens, imax);
	map.map[i[0]] = NULL;
	return (map);
}
