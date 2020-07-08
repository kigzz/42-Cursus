/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 09:25:49 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/05 09:31:07 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t size)
{
	char	*dest2;
	char	*src2;
	int		i;
	int		size_d;

	i = 0;
	*dest2 = (unsigned char *)dest;
	*src2 = (unsigned char *)src;
	size = ft_strlen(src2);
	size_d = ft_strlen(dest);
	while (i < size)
	{
		dest2[i] = src2[i];
		i++;
	}
	if (size_d > i)
	{
		while (i < size_d)
		{
			dest2[i] = '\0';
			i++;
		}
	}
	return (dest2);
}
