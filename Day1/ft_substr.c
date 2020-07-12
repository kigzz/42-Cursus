/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:29:01 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/12 16:29:02 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(s) * (len + 1))))
		return (NULL);
	else
	{
		while (len > 0 && s[i] != '\0')
		{
			dest[i] = s[start];
			start++;
			len--;
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
