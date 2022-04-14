/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:24:44 by mdoroana          #+#    #+#             */
/*   Updated: 2022/04/14 13:01:05 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			nbytes;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	nbytes = 1;
	while (1)
	{
		if (!buff[fd][0])
			nbytes = read(fd, buff[fd], BUFFER_SIZE);
		if (nbytes > 0)
			line = ft_strjoin(buff[fd], line);
		if (ft_strchr(buff[fd]) || nbytes < 1)
			break ;
	}
	return (line);
}
