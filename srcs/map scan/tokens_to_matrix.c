/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:18:55 by epainter          #+#    #+#             */
/*   Updated: 2019/11/23 07:56:29 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static	int		*len_of_rows(char ***tokens)
{
	int		i[2];
	int		*imax;

	imax = (int*)malloc(sizeof(int) * 2);
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

static	t_pixel	pxl_params(char *token, int x, int y)
{
	t_pixel	res;

	res.y = y;
	res.x = x;
	res.z = ft_atoi(token);
	res.color = 0xff000000;
	if (ft_strchr(token, ','))
		res.color = ft_atoi_base(ft_strchr(token, 'x') + 1, 16);
	res.is_exist = 1;
	return (res);
}

static	void	free_token_and_imax(char ***tokens, int *imax, t_pixel **matrix)
{
	//*matrix = NULL;
	free(tokens);
	free(imax);
}

t_pixel			**tokens_to_matrix(char ***tokens)
{
	int		i[2];
	int		*imax;
	t_pixel	**matrix;

	i[0] = -1;
	imax = len_of_rows(tokens);
	if (((matrix = (t_pixel**)malloc(sizeof(t_pixel) * imax[0])) == NULL))
		read_map_error();
	while (++i[0] < imax[0])
	{
		if ((matrix[i[0]] = (t_pixel *)malloc(sizeof(t_pixel) *\
		(imax[1] + 1))) == NULL)
			read_map_error();
		i[1] = -1;
		while ((++i[1] <= imax[1]) && tokens[i[0]][i[1]])
		{
			matrix[i[0]][i[1]] = pxl_params(tokens[i[0]][i[1]], i[1], i[0]);
			free(tokens[i[0]][i[1]]);
		}
		free(tokens[i[0]]);
		while (++i[1] <= imax[1])
			matrix[i[0]][i[1]].is_exist = 0;
		matrix[i[0]][imax[1]].is_exist = 0;
	}
	free_token_and_imax(tokens, imax, &matrix[i[0]]);
	return (matrix);
}
