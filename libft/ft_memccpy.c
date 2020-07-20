/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:10 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:12 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*dest2;
	char	*src2;
	int		i;

	dest2 = (char*)dest;
	src2 = (char*)src;
	i = 0;
	while (n > 0 && src2[i] != (char)c)
	{
		dest2[i] = src2[i];
		i++;
		n--;
		if (src2[i] == (char)c)
		{
			dest2[i] = (char)c;
			return (dest2);
		}
	}
	return (dest2);
}
