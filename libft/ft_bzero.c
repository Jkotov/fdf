/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:13:49 by epainter          #+#    #+#             */
/*   Updated: 2019/09/06 19:13:57 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	if (n == 0)
		return (s);
	str = s;
	while (--n != 0)
		*(str + n) = '\0';
	*(str + n) = '\0';
	return (s);
}