/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:49:58 by epainter          #+#    #+#             */
/*   Updated: 2019/11/22 23:09:50 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_scan.h"
#include "libft.h"

char	***string_to_tokens(char *s)
{
	char	**strings;
	char	***tokens;
	int		len;

	strings = ft_strsplit(s, '\n');
	len = 0;
	while (strings[len])
		len++;
	tokens = (char***)malloc(sizeof(char**) * len);
	tokens[len] = NULL;
	while (--len >= 0)
	{
		tokens[len] = ft_strsplit(strings[len], ' ');
		free(strings[len]);
		strings[len] = NULL;
	}
	free(strings);
	free(s);
	return (tokens);
}
