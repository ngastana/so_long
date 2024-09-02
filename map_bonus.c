/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:52:19 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/16 10:35:19 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_var *d, int y, int x, char *mapname)
{
	char	*filename;
	int		imgw;
	int		imgl;

	imgw = 400;
	imgl = 400;
	filename = ft_strjoin("./textures/", mapname);
	d->img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, filename, &imgw, &imgl);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 81 * x, 81 * y);
	free (filename);
}

void	draw_map(t_var *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d-> length)
	{
		x = 0;
		while (x < d-> width)
		{
			if (d-> array_map[y][x] == '1')
				draw_image(d, y, x, "walls.xpm");
			else
				draw_image(d, y, x, "space.xpm");
			if (d-> array_map[y][x] == 'P')
				draw_image(d, y, x, "player.xpm");
			else if (d-> array_map[y][x] == 'C')
				draw_image(d, y, x, "coins.xpm");
			else if (d-> array_map[y][x] == 'E')
				changexit(d, y, x);
			x++;
		}
		y++;
	}
}

void	changexit(t_var	*d, int y, int x)
{
	if (d-> changexit < 8)
	{
		draw_image(d, y, x, "exit1.xpm");
		d->changexit++;
	}
	else if (d-> changexit < 16)
	{
		draw_image(d, y, x, "exit2.xpm");
		d->changexit++;
	}
	else
	{
		d->changexit = 0;
		changexit(d, y, x);
	}
}

void	draw_map2(t_var *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d-> length)
	{
		x = 0;
		while (x < d-> width)
		{
			if (d->array_map[y][x] == '1')
				draw_image(d, y, x, "walls.xpm");
			else
				draw_image(d, y, x, "space.xpm");
			if (d->array_map[y][x] == 'P')
				draw_image(d, y, x, "player1.xpm");
			else if (d->array_map[y][x] == 'C')
				draw_image(d, y, x, "coins2.xpm");
			else if (d->array_map[y][x] == 'E')
				changexit(d, y, x);
			x++;
		}
		y++;
	}
}

void	draw_mapexit(t_var *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d-> length)
	{
		x = 0;
		while (x < d-> width)
		{
			if (d->array_map[y][x] == '1')
				draw_image(d, y, x, "walls.xpm");
			else
				draw_image(d, y, x, "exit2.xpm");
			if (d-> array_map[y][x] == 'P')
				draw_image(d, y, x, "player2.xpm");
			else if (d-> array_map[y][x] == 'C')
				draw_image(d, y, x, "coins2.xpm");
			else if (d-> array_map[y][x] == 'E')
				draw_image(d, y, x, "exit2.xpm");
			x++;
		}
		y++;
	}
}
