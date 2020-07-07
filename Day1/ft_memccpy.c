/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 09:16:22 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/05 09:25:17 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memccpy(void *dest, void *src, int c, unsigned int n)
{
	char	*dest2;
	char	*src2;
	int		i;

	*dest2 = (unsigned char *)dest;
	*src2 = (unsigned char *)src;
	i = 0;
	while (i < n && src2[i] != (char)c)
	{
		dest2[i] = src2[i];
		i++;
		if (src2[i] == (char)c)
		{
			dest2[i] = (char)c;
			return (dest2);
		}
	}
	return (dest2);
}
