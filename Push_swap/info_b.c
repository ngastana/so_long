/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:06:28 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/01 19:10:20 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	highest_b(t_stack *stack)
{
	int	i;

	i = 0;
	stack->highest_b = 0;
	while (i < stack->b_size)
	{
		if (stack->b[stack->highest_b] < stack->b[i])
			stack->highest_b = i;
		i++;
	}
}

void	lowest_b(t_stack *stack)
{
	int	i;

	i = 0;
	stack->lowest_b = 0;
	while (i < stack->b_size)
	{
		if (stack->b[stack->lowest_b] > stack->b[i])
			stack->lowest_b = i;
		i++;
	}
}

int	position_b(t_stack *stack, int i)
{
	int	j;
	int	position_b;

	j = 0;
	while (j < stack->b_size - 1)
	{
		if (stack->a[i] < stack->b[j] && stack->a[i] > stack->b[j + 1])
			position_b = j + 1;
		j++;
	}
	return (position_b);
}
