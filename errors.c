/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:48 by ngastana          #+#    #+#             */
/*   Updated: 2023/12/12 21:07:09 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct(char *str)
{
	if (ft_strlen(str) < 4)
		return (0);
	else if (str[ft_strlen(str)] != 'r')
		return (0);
	else if (str[ft_strlen(str) -1] != 'e')
		return (0);
	else if (str[ft_strlen(str) -2] != 'b')
		return (0);
	else if (str[ft_strlen(str) -3] != '.')
		return (0);
	return (1);
}

int	map_configuration(char *str_map)
{
	int		i;
	char	**map;
	int		j;

	i = 0;
	j = 0;
	map = ft_split(str_map, '\n');
	while (map[1][i++] != '\n')
		if (map[1][i] != 1)
			return (0);
	while (map[j][1] || map[j][i])
	{
		if (map[j][1] != 1 && map[j][i] != 1)
			return (0);
		j++;
	}
	while (map[j][i] != '\0')
	{
		if (map[j][i] != 1)
			return (0);
		i++;
	}
	return (1);
}
