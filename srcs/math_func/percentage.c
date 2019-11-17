/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 22:34:06 by epainter          #+#    #+#             */
/*   Updated: 2019/11/17 22:34:06 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	percentage(double start, double end, double cur)
{
	if ((end - start) == 0)
		return (100.0);
	return ((cur - start) / (end - start));
}