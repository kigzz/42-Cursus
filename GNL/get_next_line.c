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

/*
 * Problème de condition de retour.
 * Copie une ligne en trop quand BUFFER_SIZE trop grand
 * Factoriser la fonction gnl pour qu'elle fasse moins de 25 lignes.
 * */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	*tmpline;
	char		*buffer;
	ssize_t		index;
	static int	i;
	static char *nl;

	if (!tmpline)
		tmpline = "";
	if (!(buffer = malloc((BUFFER_SIZE) * sizeof(char))) || !line
			|| BUFFER_SIZE <= 0)
		return (-1);
	if (nl)
	{
		tmpline = nl + 1;
		if (ft_strchr(tmpline, '\n'))
		{
			line[i] = ft_strndup(tmpline, ft_strchr(tmpline, '\n') - tmpline);
			i++;
			nl = ft_strchr(tmpline, '\n');
			return (1);
		}
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
	else if (tmpline == line[i - 1])
		return (0);
	line[i] = tmpline;
	i++;
	return (1);
}

int				main(void)
{
	char **tmp;
	int fd;
	int j = 0;
	tmp = malloc(2147483647);
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	for (int i = 0; i < 8; i++)
	{
		j = get_next_line(fd, tmp);
		printf("%d. %s\n", i, tmp[i]);
		printf("return gnl = %d\n", j);
	}
	printf("_____________\n");
	for (int i = 0; tmp[i] != NULL; i++)
	{
		printf("%d. %s\n", i, tmp[i]);
	}
	return (0);
}