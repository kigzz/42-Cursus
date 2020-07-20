/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:38 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:40 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	int				i;

	i = 0;
	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	while (n > 0)
	{
		dest2[i] = src2[i];
		i++;
		n--;
	}
	return ((void*)dest);
}
