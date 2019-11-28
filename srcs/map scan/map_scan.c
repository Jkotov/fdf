/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 02:50:46 by epainter          #+#    #+#             */
/*   Updated: 2019/11/28 18:54:04 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_scan.h"

t_pixel	**map_scan(char const *file_name)
{
	char	*str;
	t_pixel	**res;

	str = read_map(file_name);
	res = string_to_tokens(str);
	return (res);
}
