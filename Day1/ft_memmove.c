/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:52 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:54 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = (char *)dst;
	src2 = (char *)src;
	if (src2 < dest2)
	{
		dest2 = dest2 + n - 1;
		src2 = src2 + n - 1;
		while (n > 0)
		{
			dest2[n] = src2[n];
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*dest2++ = *src2++;
			n--;
		}
	}
	return (dest2);
}
