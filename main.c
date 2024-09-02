/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:32:20 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/18 12:23:23 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_var *d)
{
	mlx_destroy_window (d->mlx_ptr, d->win_ptr);
	ft_free(&d);
	exit(1);
	return (0);
}

void	ft_free(t_var **d)
{
	int	i;

	i = 0;
	if ((*d)->argv != NULL)
	{
		free((*d)->argv);
		(*d)->argv = NULL;
	}
	if ((*d)->map != NULL)
	{
		free((*d)->map);
		(*d)->map = NULL;
	}
	if ((*d)->array_map != NULL)
	{
		while ((*d)->array_map[i] != NULL)
		{
			free((*d)->array_map[i]);
			(*d)->array_map[i] = NULL;
			i++;
		}
	}
	ft_free2(d);
}

void	ft_free2(t_var **d)
{
	int	i;

	i = 0;
	if ((*d)->cp != NULL)
	{
		while ((*d)->cp[i] != NULL)
		{
			free((*d)->cp[i]);
			(*d)->cp[i] = NULL;
			i++;
		}
	}
}

void	init_struc(t_var *d, char **argv, int argc)
{
	if (d == NULL)
		return ;
	d->argc = argc;
	d->argv = ft_strdup(argv[1]);
	d->map = ft_strdup("");
}

int	main(int argc, char *argv[])
{
	t_var	*d;
	char	*game_name;

	if (check_argc(argc, argv[1]) != 0)
		return (0);
	d = ft_calloc (sizeof(t_var), 1);
	init_struc (d, argv, argc);
	if (check_map(d) != 0)
	{
		ft_free(&d);
		return (ft_printf ("\n"), 0);
	}
	d->mlx_ptr = mlx_init();
	game_name = ft_strjoin("so_long - ", argv[1]);
	d->win_ptr = mlx_new_window (d->mlx_ptr, d->width * 81, d->length * 81, \
	game_name);
	free(game_name);
	d->timetoexit = 0;
	d->playermovements = 1;
	mlx_key_hook(d->win_ptr, khook, d);
	mlx_loop_hook(d->mlx_ptr, lhook, d);
	mlx_hook(d->win_ptr, 17, 0L, close_window, d);
	mlx_loop(d->mlx_ptr);
	return (0);
}
