/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:37:32 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/24 16:37:34 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Lire une ligne (Jusqu'au \n) -> Stocker la ligne dans une case de **line (strdup ftw)
 * Appeler une nouvelle fois la fonction gnl.c doit commencer au caractère après \n
 * Read jusqu'à BUFFER_SIZE ou jusqu'à \n
 *
 */
#include "get_next_line.h"
//#define BUFFER_SIZE 64

int main(void)
{
	int fd;
	int index;
	char buf[BUFFER_SIZE + 1];	// proper maloc à faire
	char **line;
	int i = 0;
	int count = 0; // pour printf line[i]
		//	Test  //
	fd = open("42", O_RDWR);
	printf("fd = %d\n", fd);
	line = (char**)malloc(9999);
		//	Test  //
	//ft_putstr_fd("Here double is a return type of function, p2f is name of the function pointer and (double, char) is an argument list\nof this function. Which means the first argument of this function is of double type and the second argument is char\ntype.\n\nLets understand this with the help of an example: Here we have a function sum that calculates the sum of two numbers\nand returns the sum. We have created a pointer f2p that points to this function, we are invoking the function using\nthis function pointer f2p.", fd);
//	index = read(fd, buf, BUFFER_SIZE);
//	printf("index = %d\n", index);
	while ((index = read(fd, buf, BUFFER_SIZE)))		// Condition si index = 0 || si \n trouvé
	{
		buf[index] = '\0';
		printf("Index = %d. buf = %s\n", index, buf);
//		printf("strchr : %s\n", ft_strchr(buf, 10));
//	If rencontre \n, copier le reste du buffer dans line[i].
//	Créer fonction strndup(const char s1, size_t n) | Elle copiera jusqu'à BUFFER_SIZE
//	Si strlen(s1) > n, n = n et '\0' à la fin. n = strlen(s1) si longueur si n > strlen(s1) et '\0' à la fin.
		line[i] = ft_strdup(buf);
		i++;
		count++;
	}
	if (index == 0)
		printf("EOF = %d\n", index);
	free(buf);
//	for (i = 0; i < count; i++)
//	{
//		printf("line %d = %s\n", i, line[i]);
//	}
	return 0;
}