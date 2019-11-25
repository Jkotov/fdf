/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:49:58 by epainter          #+#    #+#             */
/*   Updated: 2019/11/25 15:44:35 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_scan.h"
#include "libft.h"

t_pixel		**string_to_tokens(char *s)
{
	char	**strings;
	char	***tokens;
	int		len;
	t_pixel	**matrix;

	strings = ft_strsplit(s, '\n');
	len = 0;
	while (strings[len])
		len++;
	tokens = (char***)malloc(sizeof(char**) * (len + 1));
	tokens[len] = NULL;
	while (--len >= 0)
	{
		tokens[len] = ft_strsplit(strings[len], ' ');
		free(strings[len]);
		strings[len] = NULL;
	}
	matrix = tokens_to_matrix(tokens);
	free(strings);
	free(s);
	return (matrix);
}
