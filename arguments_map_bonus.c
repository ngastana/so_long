/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:57:30 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/17 12:41:29 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_var *d)
{
	d->cp = ft_split(d->map, '\n');
	d->y = 1;
	while (d->y <= d->length -2)
	{
		d->x = 1;
		while (d->x <= d->width -2)
		{
			if (d->cp[d->y][d->x] == 'P')
			{
				d->xp = d->y;
				d->yp = d->x;
				d->cp[d->y][d->x] = '-';
				return ;
			}
			d->x++;
		}
		d->y++;
	}
}

int	hyphen(t_var *d, int i)
{
	char	c;

	c = d->cp[d->y +1][d->x];
	if (c != '1' && c != '-' && c != 'E')
	{
		d->cp[d->y +1][d->x] = '-';
		i = 1;
	}
	if (c == 'E')
		d->cp[d->y +1][d->x] = '1';
	c = d->cp[d->y][d->x +1];
	if (c != '1' && c != '-' && c != 'E')
	{
		d->cp[d->y][d->x +1] = '-';
		i = 1;
	}
	if (c == 'E')
		d->cp[d->y][d->x +1] = '1';
	hyphen2(d, &i);
	return (i);
}

void	hyphen2(t_var *d, int *i)
{
	char	c;

	c = d->cp[d->y -1][d->x];
	if (c != '1' && c != '-' && c != 'E')
	{
		d->cp[d->y -1][d->x] = '-';
		*i = 1;
	}
	if (c == 'E')
		d->cp[d->y -1][d->x] = '1';
	c = d->cp[d->y][d->x -1];
	if (c != '1' && c != '-' && c != 'E')
	{
		d->cp[d->y][d->x -1] = '-';
		*i = 1;
	}
	if (c == 'E')
		d->cp[d->y][d->x -1] = '1';
}

void	drop(t_var *d)
{
	int	i;

	i = 0;
	while (d->y <= d->length -2)
	{
		while (d->x <= d->width -2)
		{
			if (d->cp[d->y][d->x] == '-')
				i = hyphen(d, i);
			d->x++;
		}
		d->x = 1;
		d->y++;
	}
	d->y = 1;
	if (i == 1)
		drop(d);
}

int	no_pec(t_var *d)
{
	while (d->y <= d->length -2)
	{
		while (d->x <= d->width -2)
		{
			if (d->cp[d->y][d->x] == 'C' || d->cp[d->y][d->x] == 'E')
				return (ft_printf("MISPLACED ARGUMENTS\n"), 1);
			d->x++;
		}
		d->x = 1;
		d->y++;
	}
	return (0);
}
