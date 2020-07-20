/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:57:05 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 21:57:13 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			number_char(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int			ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = number_char(n);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		if (n < 0)
		{
			str[i] = '-';
			i++;
			n = -n;
		}
		while (len-- > 0)
		{
			str[i] = n / ft_recursive_power(10, len) + '0';
			n = n % ft_recursive_power(10, len);
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
