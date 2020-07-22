/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:26:52 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:26:53 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	else
	{
		while (len > 0 && start <= ft_strlen(s))
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
