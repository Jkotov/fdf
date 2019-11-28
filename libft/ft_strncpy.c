/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:17:35 by epainter          #+#    #+#             */
/*   Updated: 2019/09/10 18:52:10 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (*(src + i) && len)
	{
		*(dst + i) = *(src + i);
		i++;
		if (i == len)
			break ;
	}
	while (i < len)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
