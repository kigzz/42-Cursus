/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:48:27 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/21 14:48:36 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		count;
	int		is_word;
	int		i;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	word_size(const char *s, char c, int pos)
{
	int		i;

	i = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] != c)
			i++;
		pos++;
	}
	return (i);
}

static void	split(char **array, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			if (k == 0)
				if (!(array[j] = (char*)malloc(sizeof(char*) *
						(word_size(s, c, i) + 1))))
					return ;
			array[j][k] = s[i];
			array[j][k + 1] = '\0';
			k++;
		}
		if (s[i] == c && s[i + 1] != c && k > 0)
		{
			k = 0;
			j++;
		}
	}
}

char		**ft_split(char const *s, char c)
{
	char	**array;

	if (!(array = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1))))
		return (NULL);
	split(array, s, c);
	array[count_word(s, c)] = NULL;
	return (array);
}
