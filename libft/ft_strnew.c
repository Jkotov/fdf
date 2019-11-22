/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:35:13 by epainter          #+#    #+#             */
/*   Updated: 2019/09/15 19:39:36 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	size++;
	if (size == 0)
		size--;
	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
