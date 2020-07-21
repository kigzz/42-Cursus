/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:26:44 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:26:45 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && j != ft_strlen(set))
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		i++;
	}
	return (i - 1);
}

static int	end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0 && j != ft_strlen(set))
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
		{
			j++;
		}
		i--;
	}
	return (i + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	size_t	len;

	s = start(s1, set);
	e = end(s1, set);
	if (s > e)
		len = 0;
	else
		len = e - s + 1;
	return (ft_substr(s1, s, len));
}
