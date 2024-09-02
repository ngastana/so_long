/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:30:20 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/18 09:21:13 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argc(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("Error\n");
		ft_printf("Inappropriate number of arguments\n");
		return (1);
	}
	if (check_extension(argv) == 1)
	{
		ft_printf("Error\n");
		ft_printf("Map with invalid extension\n");
		return (1);
	}
	return (0);
}

void	get_map(t_var *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map[i] == '\n')
		i++;
	if (d->map[i] == '\0')
	{
		ft_printf("Error\n");
		ft_printf("The archive has not got a map\n");
		ft_free(&d);
		exit (1);
	}
	while (d->map[i] != '\0')
	{
		d->map[j] = d->map[i];
		i++;
		j++;
	}
	d->map[j] = '\0';
}

void	read_map(t_var *d)
{
	int		fd;
	char	*str;
	int		readbytes;
	char	*aux;

	readbytes = 1;
	fd = open(d->argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nError opening map\n");
		ft_free(&d);
		exit (1);
	}
	while (readbytes != 0)
	{
		aux = d->map;
		str = ft_calloc(sizeof(char), 2);
		readbytes = read(fd, str, 1);
		d->map = ft_strjoin(aux, str);
		free (aux);
		free (str);
	}
	close(fd);
	get_map(d);
	d->array_map = ft_split(d->map, '\n');
}

int	dimensions(t_var *d)
{
	int	i;

	d->width = 0;
	d->length = 0;
	i = 0;
	while (d->array_map[0][d->width] != '\0')
		d->width++;
	while (d->map[i] != '\0')
	{
		if (d->map[i] == '\n')
		{
			if (d->map[i +1] != '1')
				return (ft_printf ("Error\nInvalid map\n"), 1);
			else
				d->length++;
		}
		i++;
	}
	d->length++;
	return (0);
}
