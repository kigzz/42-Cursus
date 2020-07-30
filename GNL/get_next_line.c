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
//	static char	*tmp;
	char		*buf;
	int			index;
	static int			i;

//	fd = open("42", O_RDWR);
//	printf("fd = %d\n", fd);
//	printf("i = %d\n", i);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))) && !line && BUFFER_SIZE <= 0)
		return (-1);
	while ((index = read(fd, buf, BUFFER_SIZE)) && !ft_strchr(buf, '\n'))
	{
//		printf("Index = %d\n", index);
		buf[index] = '\0';
		line[i] = ft_strndup(buf, BUFFER_SIZE);	// comment dire "reprends au char après \n"?
//		printf("Index = %d | Line[%d] = %s\n", index, i, line[i]);
		i++;
	}
	char *n1 = ft_strchr(buf, '\n');
	printf("strchr = %s\n", n1);
	if (ft_strchr(buf, '\n')) {
		printf("index = %d\n", index);
		printf("buf = %s\n", buf);
		printf("strjoin = %s\n", ft_strjoin(buf, n1));
	}
//	if (ft_strchr(buf, '\n') != NULL)
//		line[i] = "Ta mère";//ft_strjoin(nl + 1, buf);
//	free(buf);
	return (0);
}

int				main(void)
{
	char **tmp;
	int fd;
	tmp = malloc(9999);
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	for (int i = 0; i < 1; i++)
	{
		get_next_line(fd, tmp);
//		printf("_____________\n");
//		printf("%d. %s\n", i, tmp[i]);
	}
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d. %s\n", i, tmp[i]);
//	}
	return (0);
}