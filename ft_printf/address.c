/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:09 by bpouchep          #+#    #+#             */
/*   Updated: 2021/12/06 15:52:12 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_address(unsigned long int n, char *base)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n >= ft_strlen (base))
	{
		n = n / ft_strlen (base);
		size++;
	}
	if (n % ft_strlen (base))
		size++;
	return (size);
}

int	ft_putbase_address(unsigned long int n, char *base)
{
	if (n >= ft_strlen (base))
	{
		ft_putbase (n / ft_strlen (base), base);
		ft_putchar (base[n % ft_strlen (base)]);
	}
	else
		ft_putchar (base[n]);
	return (ft_intlen_address (n, base));
}
