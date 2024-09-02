/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:56:58 by ngastana          #+#    #+#             */
/*   Updated: 2024/01/18 08:33:15 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include "libmlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h> // para open
# include <unistd.h> // para read, write y exit

typedef struct s_var
{
	char	*argv;
	int		argc;
	int		width;
	int		length;
	char	*map;
	char	**array_map;
	char	**cp;
	int		air;
	int		wall;
	int		finish;
	int		player;
	int		c;
	int		x;
	int		y;
	int		xp;
	int		yp;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		timetoexit;
	int		playermovements;
	int		changexit;
}				t_var;

/*check_map*/
int		check_extension(char *str);
int		is_closed_by_walls(t_var *d);
int		is_rectangular(t_var *d);
int		check_map(t_var *d);
int		map_arguments(t_var *d);

/* arguments_map */
void	find_player(t_var *d);
int		hyphen(t_var *d, int i);
void	drop(t_var *d);
int		no_pec(t_var *d);
void	hyphen2(t_var *d, int *i);

/*utils*/
int		check_argc(int argc, char *argv);
void	read_map(t_var *d);
int		dimensions(t_var *d);
void	get_map(t_var *d);

/*map*/
void	draw_image(t_var *d, int y, int x, char *mapname);
void	draw_map(t_var *d);
void	draw_map2(t_var *d);
void	draw_mapexit(t_var *d);
void	changexit(t_var	*d, int y, int x);

/*main*/
void	ft_free(t_var **d);
void	ft_free2(t_var **d);
void	init_struc(t_var *d, char **argv, int argc);
int		close_window(t_var *d);

/*movements*/
int		khook(int keycode, t_var *d);
int		lhook(t_var *d);
void	playermove(t_var *d, int new_x, int new_y);
void	changeimagen(t_var *d, int new_x, int new_y);
void	draw_map2(t_var *d);

/*movements_bonus*/
char	*print_movements(t_var *d);

#endif