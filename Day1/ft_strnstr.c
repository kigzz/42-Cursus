/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:04:00 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/07 17:04:01 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int i;
	int j;
	int size_find;

	i = 0;
	size_find = 0;
	while (to_find[size_find] != '\0')
		size_find++;
	if (size_find == 0)
		return (str);
	while (str[i] != '\0' && n > i)
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j] && n > i + j)
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		else
			i++;
	}
	return (0);
}
