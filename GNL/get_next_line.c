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

int 			get_next_line(int fd, char **line) {
	static char *tmpline;
	char *buffer;
	ssize_t index;
	char *nl;

	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))) || !line || BUFFER_SIZE <= 0) {
		return (-1);
	}
//	printf("tmpline = %s\n", tmpline);
	while ((!(nl = ft_strchr(tmpline, '\n')) &&
			(index = read(fd, buffer, BUFFER_SIZE)) != 0))
	{
//		printf("0buffer =%s\n", buffer);
		if (index == -1) {
			free(buffer);
			return (-1);
		}
		buffer[index] = '\0';
		if (tmpline)
			tmpline = ft_strjoin(tmpline, buffer);
		else
			tmpline = ft_strndup(buffer, index);
//		printf("tmpline = %s\n", tmpline);
	}
//	printf("NEW LINE = %s\n", nl);
	if (nl) {
//		printf("tmplinenl = %s\n", tmpline);
//		printf("1nl = %s\n", nl);
		*line = ft_strndup(tmpline, nl - tmpline);
		tmpline = ft_strndup(nl + 1, BUFFER_SIZE);
//		printf("tmpline after strjoin = %s\n", tmpline);
		free(buffer);
		return (1);
	}
//	printf("eof line = %s\n", *line);
//	printf("eof tmpline = %s\n", tmpline);
//	printf("strcmp eof line/tmpline = %d\n", ft_strcmp(*line, tmpline));
	if (tmpline)
		*line = tmpline;
	else
		*line = ft_strndup("\0", 1);
	tmpline = NULL;
//	free(buffer);
//	free(tmpline);
	return (0);
}

/*
int main(void)
{
	char **tmp;
	int fd;
	int j = 0;
	tmp = malloc(2147483647);
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	for (int i = 0; i < 9; i++)
	{
		j = get_next_line(fd, tmp);
		printf("%d. %s\n", i, tmp[0]);
		printf("----> return gnl = %d\n", j);
//		printf("_____________\n");
	}
	return (0);
}
*/
