/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:44:30 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/12 14:12:51 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_space(t_stack *stack, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] == ' ')
		i++;
	while (argv[1][i] != '\0')
	{
		while (argv[1][i] == ' ' && argv[1][i +1] == ' ')
			i++;
		if (argv[1][i] == ' ' && argv[1][i +1] == '\0')
			i++;
		if (argv[1][i] == ' ')
			stack->a_size = stack->a_size +1;
		i++;
	}
}

void	init_stacks(t_stack *stack, int argc, char **argv)
{
	stack->a_size = 1;
	if (argc == 2)
		check_space(stack, argv);
	else
		stack->a_size = argc -1;
	stack->a = malloc (sizeof(int) * stack->a_size);
	stack->b = malloc (sizeof(int) * stack->a_size);
	if (!(stack->b || stack->a))
		free_exit(stack, "Error\n");
}

static int	check_int_max_min(long num)
{
	if (num < INT_MIN)
		return (1);
	else if (num > INT_MAX)
		return (1);
	return (0);
}

static void	fill_stack_argu_two(t_stack *stack, char **argv)
{
	char	**split;
	int		i;
	long	num;

	i = 0;
	split = ft_split(argv[1]);
	if (!(split))
		free_exit(stack, "Error\n");
	while (split[i])
	{
		num = atoi_long(split[i]);
		if (check_int_max_min(num) == 1)
			free_exit(stack, "Error\n");
		stack->a[i] = atoi_long(split[i]);
		i++;
	}
	free (split);
}

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
		fill_stack_argu_two(stack, argv);
	else
	{
		while (i < argc -1)
		{
			check_phrase(stack, argv[i +1]);
			stack->a[i] = atoi_long(argv[i +1]);
			if (!(stack->a[i]) && stack->a[i] != 0)
				free_exit(stack, "Error\n");
			i++;
		}
	}
}
