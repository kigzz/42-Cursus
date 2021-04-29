/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:46:56 by bpouchep          #+#    #+#             */
/*   Updated: 2020/08/21 18:47:25 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_nl(char **line, char **tmpline, char **buf)
{
	const char	*tmp = *tmpline;
	const char	*nl = ft_strchr(*tmpline, '\n');

	if (nl)
	{
		*line = ft_strndup(tmp, nl - tmp);
		*tmpline = ft_strndup(nl + 1, BUFFER_SIZE);
		free((void *)tmp);
		free(*buf);
		return (1);
	}
	*line = (*tmpline) ? *tmpline : ft_strndup("", 1);
	*tmpline = NULL;
	free(*buf);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *tmpline;
	char		*buff;
	char		*nl;
	char		*tmp;
	ssize_t		index;

	if (!(buff = malloc((sizeof(char) * (BUFFER_SIZE + 1))))
			|| !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((!(nl = ft_strchr(tmpline, '\n')) &&
			(index = read(fd, buff, BUFFER_SIZE)) != 0))
	{
		if (index == -1)
		{
			free(buff);
			return (-1);
		}
		buff[index] = '\0';
		tmp = (tmpline) ? ft_strjoin(tmpline, buff) : ft_strndup(buff, index);
		free(tmpline);
		tmpline = tmp;
	}
	return (ft_nl(line, &tmpline, &buff));
}
