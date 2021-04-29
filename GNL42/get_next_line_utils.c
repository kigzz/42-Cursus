/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:37:48 by bpouchep          #+#    #+#             */
/*   Updated: 2021/04/28 17:43:58 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	const char	*str2;

	str2 = str;
	while (*str != '\0')
		str++;
	return (str - str2);
}

char			*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;
	size_t	len;

	i = 0;
	if (ft_strlen(src) > n)
		len = n;
	else
		len = ft_strlen(src);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			i;
	const size_t	str_len = ft_strlen(s1) + ft_strlen(s2);

	if (!(str = malloc((str_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char			*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)&str[i]);
}
