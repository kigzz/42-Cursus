/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:06:24 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/27 19:06:41 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	*buf;
	int			index;
	int			i;

	i = 0;
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((index = read(fd, buf, BUFFER_SIZE)) && ft_strchr(buf, '\n') == NULL)
	{
		buf[index] = '\0';
		line[i] = ft_strndup(buf, BUFFER_SIZE);	// comment dire "stop toi quand t'as trouvé \n" ?
		i++;
	}
	return (0);
}

int				main(void)
{
	char **tmp;
	tmp = malloc(9999);
	get_next_line(3, tmp);
	for (int i = 0; i < 16; i++)
	{
		printf("%d. %s\n", i, tmp[i]);
	}
	return (0);
}