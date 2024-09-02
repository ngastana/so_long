/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:38:53 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/05 07:51:00 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char	*deposit, char const	buffer[BUFFER_SIZE +1])
{
	int		i;
	int		j;
	char	*str;

	if (!deposit)
	{
		deposit = (char *)malloc(1 * sizeof(char));
		deposit[0] = '\0';
	}
	if (!deposit || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(deposit) + ft_strlen(buffer) + 1));
	if (str == NULL)
		return (0);
	i = -1;
	j = 0;
	if (deposit)
		while (deposit[++i] != '\0')
			str[i] = deposit[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(deposit) + ft_strlen(buffer)] = '\0';
	free (deposit);
	return (str);
}
