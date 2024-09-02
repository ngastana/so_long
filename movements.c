/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:57:13 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/17 15:09:40 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	khook(int keycode, t_var *d)
{
	if (keycode == 53)
	{
		ft_printf("YOU GAVE UP!\nIs it to hard for you?\n");
		close_window(d);
	}
	else if (keycode == 13)
		playermove(d, -1, 0);
	else if (keycode == 0)
		playermove(d, 0, -1);
	else if (keycode == 1)
		playermove(d, 1, 0);
	else if (keycode == 2)
		playermove(d, 0, 1);
	return (0);
}

void	playermove(t_var *d, int new_x, int new_y)
{
	if (d -> array_map[d->xp + new_x][d->yp + new_y] != '1')
	{
		ft_printf("You moved %i times.\n", d->playermovements);
		d->playermovements++;
		if (d->timetoexit != 0)
			d->timetoexit = 1;
		else
			d->timetoexit = 0;
		if (d->array_map[d->xp + new_x][d->yp + new_y] == 'C')
			d->c--;
		else if (d->array_map[d->xp + new_x][d->yp + new_y] == 'E' && d->c == 0)
			d->timetoexit = 2;
		if (d->array_map[d->xp + new_x][d->yp + new_y] == 'E' && d->c != 0)
		{
			new_x = 0;
			new_y = 0;
			d->playermovements--;
		}
		d->array_map[d->xp][d->yp] = '0';
		d->array_map[d->xp + new_x][d->yp + new_y] = 'P';
		d->xp += new_x;
		d->yp += new_y;
	}
}

int	lhook(t_var *d)
{
	if (d->timetoexit > 1)
	{
		draw_mapexit(d);
		d -> timetoexit++;
		if (d->timetoexit == 5)
		{
			ft_printf("YOU FINISH! Congratulations!\n");
			close_window(d);
		}
	}
	else
		draw_map(d);
	return (0);
}
