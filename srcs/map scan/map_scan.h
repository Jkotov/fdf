/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:07:47 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SCAN_H
# define MAP_SCAN_H

# include "stdlib.h"
# include "fdf.h"

char	*read_map(char const *file_name);
t_map	string_to_tokens(char *s);
t_map	tokens_to_matrix(char ***tokens);

#endif
