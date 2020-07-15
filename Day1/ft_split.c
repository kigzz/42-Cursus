/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:24:14 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:24:15 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		count_word(char *str, char *charset)
{
	int		count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (is_sep(*str, charset))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		word_size(char *str, char *charset, int pos)
{
	int		i;

	i = 0;
	while (str[pos])
	{
		if (!is_sep(str[pos], charset))
			i++;
		pos++;
	}
	return (i);
}

void	split_init(char **array, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i] != '\0')
	{
		if (!is_sep(str[i], charset))
		{
			if (k == 0)
				if (!(array[j] = malloc(sizeof(char*) *
										(word_size(str, charset, i) + 1))))
					return ;
			array[j][k] = str[i];
			array[j][k + 1] = '\0';
			k++;
		}
		if (is_sep(str[i], charset) && !is_sep(str[i + 1], charset) && k > 0)
		{
			k = 0;
			j++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char **array;

	if (!(array = malloc(sizeof(char*) * (count_word(str, charset) + 1))))
		return (NULL);
	split_init(array, str, charset);
	array[count_word(str, charset)] = NULL;
	return (array);
}
