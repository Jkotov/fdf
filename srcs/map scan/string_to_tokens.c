/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:49:58 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_scan.h"
#include "libft.h"

t_map	string_to_tokens(char *s)
{
	char	**strings;
	char	***tokens;
	int		len;
	t_map	map;

	strings = ft_strsplit(s, '\n');
	len = 0;
	while (strings[len])
		len++;
	if (!(tokens = (char***)malloc(sizeof(char**) * (len + 1))))
		read_map_error();
	tokens[len] = NULL;
	while (--len >= 0)
	{
		tokens[len] = ft_strsplit(strings[len], ' ');
		free(strings[len]);
		strings[len] = NULL;
	}
	map = tokens_to_matrix(tokens);
	free(strings);
	free(s);
	return (map);
}
