/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:56:21 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/13 16:56:50 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// s'arrête à la première itération qui n'est pas dans le *set
// Début + Fin
// connaitre strlen de dest (Faire fonction?)
// OU connaitre début + fin et return substr?

int			start(char const *s1, char const *set) {
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] != '\0') {
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j]) {
			j++;
		}
		if (j == ft_strlen(set))
			break;
		i++;
		if (i == ft_strlen(s1))
			return (0);
	}
	return (i);
}

int			end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
		{
			j++;
		}
		if (j == ft_strlen(set))
			break;
		i--;
		if (i == 0)
			return (ft_strlen(s1));
	}
	printf("i_end = %ld\n", i);
	return (i);
}

//char		*ft_strtrim(char const *s1, char const *set)
//{
//	char	*dest;
//
//}

int main (void)
{
	char str[30] = "ABCABCAB";
	char set[30] = "";
	int i = start(str, set);
	int j = end(str, set);

	printf("%d\n%c\n", i, str[i]);
	printf("%d\n%c\n", j, str[j]);
}