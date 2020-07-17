/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:45:53 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/17 13:47:15 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*last_ele;

	if (!(last_ele = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
		last_ele = lst;
	}
	return (last_ele);
}
