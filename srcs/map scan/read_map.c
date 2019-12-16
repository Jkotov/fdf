/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:36:26 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_scan.h"
#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFSIZE 1024

char	*read_map(char const *file_name)
{
	int		ret;
	int		fd;
	char	*s;
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFFSIZE + 1))))
		read_map_error();
	fd = open(file_name, O_RDONLY);
	s = ft_strnew(0);
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		ft_bzero((buf + ret), BUFFSIZE - ret + 1);
		s = ft_strjoinfree(&s, &buf, 1);
		if (s == NULL)
			read_map_error();
	}
	free(buf);
	if (ret < 0 || *s == 0)
		read_map_error();
	return (s);
}
