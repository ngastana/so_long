/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:12:03 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/06 11:47:54 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == ',');
}

static int	ft_words_len(char *str)
{
	int	idx;
	int	length;

	idx = 0;
	length = 0;
	while (str[idx] != '\0')
	{
		if (!ft_is_delimiter(str[idx]))
		{
			length++;
			idx++;
		}
		else
			idx++;
	}
	return (length);
}

static char	*ft_get_word(char *str)
{
	int			idx;
	char		*word;

	idx = 0;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
		idx++;
	word = (char *)malloc(sizeof(char) * (idx + 1));
	if (!word)
		return (NULL);
	idx = 0;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		idx;
	char	**split;

	idx = 0;
	split = (char **)malloc(sizeof(char *) * ft_words_len(str) + 1);
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_delimiter(*str))
			str++;
		if (*str && !ft_is_delimiter(*str))
		{
			split[idx] = ft_get_word(str);
			idx++;
		}
		while (*str && !ft_is_delimiter(*str))
			str++;
	}
	split[idx] = NULL;
	return (split);
}
