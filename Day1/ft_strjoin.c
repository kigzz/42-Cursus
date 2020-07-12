/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:51:11 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/12 18:42:52 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		end;

	i = 0;
	end = 0;
	if (!(dest = (char*)malloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
		end = i;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dest[end] = s2[i];
		i++;
		end++;
	}
	dest[end] = '\0';
	return (dest);
}
