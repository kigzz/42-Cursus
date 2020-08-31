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

/*int				get_next_line(int fd, char **line)
{
	static char	*tmpline;
	static char *nl;
	static int	i = -1;
	ssize_t		index;
	char		*buffer;

	if (!tmpline)
		tmpline = "\0";
	if (nl)
	{
		tmpline = nl + 1;
		if (ft_strchr(tmpline, '\n'))
		{
			line[++i] = ft_strndup(tmpline, ft_strchr(tmpline, '\n') - tmpline);
			nl = ft_strchr(tmpline, '\n');
			return (1);
		}
	}
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))) || !line
		|| BUFFER_SIZE <= 0) {
		return (-1);
	}
	while ((index = read(fd, buffer, BUFFER_SIZE)) &&
			!(nl = ft_strchr(buffer, '\n')))
	{
		if (index == -1)
			return (-1);
		buffer[index] = '\0';
		tmpline = ft_strjoin(tmpline, buffer);
	}
	if (nl)
		tmpline = ft_strjoin(tmpline, ft_strndup(buffer, nl - buffer));
	if (i > 0 && !ft_strcmp(line[i], tmpline))
		return (0);
	line[++i] = tmpline;
	return (1);
}*/

int 			get_next_line(int fd, char **line)
{
	static char 	*tmpline;
	char			*buffer;
	ssize_t 		index;
	char 			*nl;

	if (tmpline == NULL)
		tmpline = "\0";
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))) || !line || BUFFER_SIZE <= 0) {
		return (-1);
	}
//	printf("tmpline = %s\n", tmpline);
	while (!(nl = ft_strchr(tmpline, '\n')) && (index = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
//		printf("0buffer =%s\n", buffer);
		if (index == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[index] = '\0';
		tmpline = ft_strjoin(tmpline, buffer);
//		printf("tmpline = %s\n", tmpline);
	}
//	printf("NEW LINE = %s\n", nl);
	if (nl)
	{
//		printf("3buffer nl = %s\n", buffer);
		*line = ft_strndup(tmpline, nl - tmpline);
		tmpline = ft_strndup(nl + 1, BUFFER_SIZE);
//		printf("tmpline after strjoin = %s\n", tmpline);
		free(buffer);
		return (1);
	}
	*line = tmpline;
	free(buffer);
	return (0);

}
int				main(void)
{
	char **tmp;
	int fd;
//	int j = 0;
	tmp = malloc(2147483647);
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	for (int i = 0; i < 7; i++)
	{
		get_next_line(fd, tmp);
		printf("--> line = %s\n", tmp[0]);
//		printf("--> return gnl = %d\n", j);
//		printf("_____________\n");
	}
	return (0);
}
