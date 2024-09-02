/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:48 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/18 09:23:15 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *str)
{
	if (ft_strlen(str) < 4)
		return (1);
	else if (str[ft_strlen(str) -1] != 'r')
		return (1);
	else if (str[ft_strlen(str) -2] != 'e')
		return (1);
	else if (str[ft_strlen(str) -3] != 'b')
		return (1);
	else if (str[ft_strlen(str) -4] != '.')
		return (1);
	return (0);
}

int	is_closed_by_walls(t_var *d)
{
	int		i;
	int		j;
	char	*map;

	i = 0;
	while (i < d->length)
	{
		if (i == 0 || i == d->length -1)
		{
			j = 0;
			while (j < d->width)
			{
				if (d->array_map[i][j] != '1')
					return (ft_printf("Error\nProblems with walls\n"), 1);
				j++;
			}
		}
		map = d->array_map[i];
		j = ft_strlen(map);
		if (j != d->width || map[0] != '1' || map[d->width - 1] != '1')
			return (ft_printf("Error\nProblems with walls\n"), 1);
		i++;
	}
	return (0);
}

int	is_rectangular(t_var *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->array_map[i])
	{
		if (ft_strlen(d->array_map[i]) != d->width)
			return (ft_printf("Error\nIs not rectangular\n"), 1);
		i++;
	}
	if (i != d->length)
		return (ft_printf("Error\nIs not rectangular\n"), 1);
	return (0);
}

int	check_map(t_var *d)
{
	int	i;

	i = 0;
	read_map(d);
	i = dimensions (d);
	i = is_closed_by_walls(d) + i;
	i = is_rectangular(d) + i;
	i = map_arguments(d) + i;
	find_player(d);
	drop(d);
	i = no_pec(d) + i;
	if (i != 0)
		ft_free(&d);
	return (i);
}

int	map_arguments(t_var *d)
{
	int	i;
	int	j;

	i = -1;
	d->player = 0;
	d->finish = 0;
	d->c = 0;
	while (i++ < d->length -1)
	{
		j = -1;
		while (j++ < d->width -1)
		{
			if (d->array_map[i][j] == 'P')
				d->player++;
			else if (d->array_map[i][j] == 'E')
				d->finish++;
			else if (d->array_map[i][j] == 'C')
				d->c++;
			else if (d->array_map[i][j] != '1' && d->array_map[i][j] != '0')
				return (ft_printf("Error\nElements must be:P,E,C,0 or 1\n"), 1);
		}
	}
	if (d->player != 1 || d->finish != 1 || d->c == 0)
		return (ft_printf("Error\nMissing elements in the map\n"), 1);
	return (0);
}
