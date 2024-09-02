/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:03:27 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/12 15:02:36 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int_max_min(char	**argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		num = atoi_long(argv[i]);
		if (num < INT_MIN)
			return (1);
		else if (num > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

static int	check_util(char c, char c1)
{
	if ((c == '+' || c == '-') && c1 == '\0')
		return (1);
	else if (c == '+' && c1 == ' ')
		return (1);
	else if (c == '-' && c1 == ' ')
		return (1);
	else if (c == '-' && c1 == '-')
		return (1);
	else if (c == '+' && c1 == '-')
		return (1);
	else if (c == '-' && c1 == '+')
		return (1);
	else if (c == '+' && c1 == '+')
		return (1);
	else if ((c < '9' && c > '0') && (c1 == '-' || c1 == '+'))
		return (1);
	else if (c == ' ' || c == '-' || c == '+')
		return (0);
	else if ((c > '9' || c < '0'))
		return (1);
	else
		return (0);
}

void	check_arguments(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[1][0] == ',')
				free_exit (NULL, "Error\n");
			if (check_util(argv[i][j], argv[i][j +1]) == 1)
				free_exit (NULL, "Error\n");
			else if (check_int_max_min(argv) == 1)
				free_exit (NULL, "Error\n");
			j++;
		}
		i++;
	}
}

void	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		while (j < stack->a_size)
		{
			if (stack->a[i] == stack->a[j])
				free_exit (stack, "Error\n");
			j++;
		}
		i++;
	}
}

void	check_phrase(t_stack *stack, char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		free_exit (stack, "Error\n");
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ' || argv[i] == '\n' || argv[i] == '\t' \
		|| argv[i] == '\v' || argv[i] == '\f' || argv[i] == '\r')
			free_exit (stack, "Error\n");
		i++;
	}
}
