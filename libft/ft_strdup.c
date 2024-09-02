/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:18:49 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/02 18:37:41 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int			i;
	char		*arr;

	arr = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	arr = malloc (sizeof(char) * (ft_strlen(s) +1));
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/* int	main()
{
	const char	*s;

	s = "amatxu";
	printf("%s\n", strdup(s));
}
 */