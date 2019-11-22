/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:39:12 by epainter          #+#    #+#             */
/*   Updated: 2019/09/27 17:42:51 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	while (len)
	{
		*(res + len) = *(str + len);
		len--;
	}
	*res = *str;
	return (res);
}