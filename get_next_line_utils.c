/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:24:42 by mdoroana          #+#    #+#             */
/*   Updated: 2022/04/14 12:51:56 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

int	ft_strchr(char *str)
{
	int	i;
	int	cond;
	int	j;

	i = 0;
	j = 0;
	cond = 0;
	while (str[i])
	{
		if (cond == 1)
		{
			str[j] = str[i];
			j++;
		}
		if (str[i] == '\n')
			cond = 1;
		str[i] = 0;
		i++;
	}
	return (cond);
}

char	*ft_strjoin(char *buff, char *line)
{
	int		buff_len;
	int		line_len;
	int		i;
	int		j;
	char	*newstr;

	buff_len = ft_strlen(buff);
	line_len = ft_strlen(line);
	newstr = malloc(sizeof(char) * (buff_len + line_len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i])
		newstr[j++] = line[i++];
	i = 0;
	while (i < buff_len)
		newstr[j++] = buff[i++];
	newstr[j] = '\0';
	if (line)
		free(line);
	return (newstr);
}
