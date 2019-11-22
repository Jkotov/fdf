/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:18:55 by epainter          #+#    #+#             */
/*   Updated: 2019/11/22 23:48:27 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_pixel		**tokens_to_matrix(char ***tokens)
{
	int		i[3];

	ft_memset(i, 0, 3 * sizeof(int) / sizeof(char));
	while (tokens[i[0]])
	{
		while (tokens[i[0]][i[1]])
		{
			while (tokens[i[0]][i[1]][i[2]])
			{

			}
		}
	}
}