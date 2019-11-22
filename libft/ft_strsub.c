/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:16:49 by epainter          #+#    #+#             */
/*   Updated: 2019/09/15 18:40:46 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	res = ft_strnew(len);
	if (res == NULL || s == NULL)
		return (NULL);
	if (len == 0)
		return (res);
	*(res + len) = '\0';
	while (--len)
	{
		*(res + len) = *(s + len + start);
	}
	*res = *(s + start);
	return (res);
}
