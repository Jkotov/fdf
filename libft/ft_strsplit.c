/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:08:48 by epainter          #+#    #+#             */
/*   Updated: 2019/11/25 10:19:40 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	words_counter(const char *s, char c)
{
	size_t	c_words;
	size_t	i;

	c_words = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == '\0'))
			c_words++;
		i++;
	}
	return (c_words);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	prev;
	char	**res;

	if (s == NULL)
		return (NULL);
	prev = 0;
	i = 0;
	j = 0;
	res = (char**)malloc(sizeof(char*) * (words_counter(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == c)
			prev = i + 1;
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == '\0'))
		{
			*(res + j++) = ft_strsub(s, prev, i - prev + 1);
		}
		i++;
	}
	*(res + j) = NULL;
	return (res);
}
