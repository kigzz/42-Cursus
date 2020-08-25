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

int				get_next_line(int fd, char **line)
{
	static char	*tmpline;
	char		*buf;
	ssize_t		index;
	static int	i;
	static char *nl;

	if (!tmpline)
		tmpline = "";
//==	printf("strchr = %s\n-------\n", nl);
//		printf("Index = %d | Line[%d] = %s\n", index, i, line[i]);
//	fd = open("42", O_RDWR);
//	printf("fd = %d\n", fd);
//	printf("i = %d\n", i);
	if (!(buf = malloc((BUFFER_SIZE) * sizeof(char))) || !line || BUFFER_SIZE <= 0)
		return (-1);
/*	Fonction checkant le reste après \n.
	Si \n présent dans le reste, enregistre dans **line
 	Redéfinit nl pour boucler.
 	Se termine quand nl == NULL. Dans ce cas,
*/
	while (nl)
	{
		tmpline = nl + 1;
		if (ft_strchr(tmpline, '\n'))
		{
//			printf("tmpline if NL présent : %s\n", tmpline);
			line[i] = ft_strndup(tmpline, ft_strchr(tmpline, '\n') - tmpline);
//			printf("line : %s\n", line[i]);
			i++;
		}
		nl = ft_strchr(tmpline, '\n');
//		printf("nl if nl != null : %s\n", nl);
	}

/*	Dans le cas où BUFFER_SIZE n'est pas assez grand pour aller jusqu'à une \n
 *  Concaténation de buf successifs jusqu'à \n
 */

	while ((index = read(fd, buf, BUFFER_SIZE)) && !(nl = ft_strchr(buf, '\n')))
	{
		if (index == -1) {
			return (-1);
		}
		buf[index] = '\0';
//		if (!tmpline) {
//			tmpline = ft_strndup(buf, BUFFER_SIZE);
//==			printf("if !(tmpline) = %s\n", tmpline);
//		}
//		else {
			tmpline = ft_strjoin(tmpline, buf);
			printf("if (tmpline) = %s\n", tmpline);
//		}
	}

//	printf("strchr = %s\n-------\n", nl);

/* 	Fonction permettant de concaténer le reste après \n
 * 	Enregistrement dans tmpline
 */
	if (nl)
	{
//		printf("index = %ld\n", index);
//		printf("i = %d\n", i);
		printf("nl = %s\n", nl);
		printf("buf = %s\n", buf);
		printf("before tmpline = %s\n", tmpline);
//		printf("strjoin = %s\n", ft_strjoin(tmpline, ft_strndup(buf, nl - buf)));
		printf("strndup = %s\n", ft_strndup(buf, nl - buf));	//		nl pointe à l'endroit 5. buf pointe à l'endroit 0
//		printf("strchr - buf = %ld\n", nl - buf);
//		tmpline = ft_strjoin(tmpline, (ft_strndup(buf, nl - buf)));
		tmpline = ft_strjoin(tmpline, ft_strndup(buf, nl - buf));
	}
//	printf("index = %ld\n", index);
	printf("FINAL TMPLINE = %s\n", tmpline);
//	printf("index check = %ld\n", index);
	line[i] = tmpline;
	i++;
	return (1);
}

int				main(void)
{
	char **tmp;
	int fd;
	tmp = malloc(2147483647);
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	for (int i = 0; i < 8; i++)
	{
		get_next_line(fd, tmp);
//		printf("_____________\n");
		printf("%d. %s\n", i, tmp[i]);
		printf("return gnl = %d\n", get_next_line(fd, tmp));
	}
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d. %s\n", i, tmp[i]);
//	}
	return (0);
}