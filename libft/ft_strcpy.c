/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:05:59 by epainter          #+#    #+#             */
/*   Updated: 2019/12/05 14:15:47 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = *(src + i);
	return (dst);
}
