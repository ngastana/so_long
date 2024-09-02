/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:49:28 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/02 09:04:55 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_table(t_stack	*stack)
{
	int	i;
	int	j;

	i = 0;
	stack->table = (int **)malloc(sizeof(int *) * (stack->a_size));
	while (i < stack->a_size)
	{
		stack->table[i] = (int *)malloc(sizeof(int) * (12));
		j = 0;
		while (j < 12)
		{
			stack->table[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	pos_b(t_stack *stack, int i)
{
	int	pos_b;
	int	pos_0;

	pos_b = 0;
	pos_0 = stack->b[0];
	if (stack->a[i] < stack->b[stack->lowest_b])
	{
		if (stack->lowest_b == stack->b_size - 1)
			pos_b = 0;
		else
			pos_b = stack->lowest_b + 1;
	}
	else if (stack->a[i] > stack->b[stack->highest_b])
	{
		if (stack->highest_b == 0)
			pos_b = 0;
		else
			pos_b = stack->highest_b;
	}
	else if (stack->a[i] > pos_0 && stack->a[i] < stack->b[stack->b_size - 1])
		pos_b = 0;
	else
		pos_b = position_b(stack, i);
	return (pos_b);
}

void	fill_table(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size)
	{
		stack->table[i][2] = i;
		stack->table[i][3] = pos_b(stack, i);
		stack->table[i][5] = stack->a_size - i;
		if (i == 0)
			stack->table[i][5] = 0;
		stack->table[i][6] = stack->b_size - pos_b(stack, i);
		if (pos_b(stack, i) == 0)
			stack->table[i][6] = 0;
		stack->table[i][7] = stack->table[i][2];
		stack->table[i][8] = stack->table[i][6];
		stack->table[i][9] = stack->table[i][5];
		stack->table[i][10] = stack->table[i][3];
		i++;
	}
}

int	movements_num(t_stack *s, int i)
{
	s->r = s->table[i][1] + s->table[i][2] + s->table[i][3];
	s->rr = s->table[i][4] + s->table[i][5] + s->table[i][6];
	s->rarrb = s->table[i][7] + s->table[i][8];
	s->rbrra = s->table[i][9] + s->table[i][10];
	while (i < s->a_size)
	{
		if (s->r <= s->rr && s->r <= s->rarrb && s->r <= s->rbrra)
			return (s->table[i][11] = 1, s->r);
		else if (s->rr <= s->rarrb && s->rr <= s->rbrra)
			return (s->table[i][11] = 2, s->rr);
		else if (s->rarrb <= s->rbrra)
			return (s->table[i][11] = 3, s->rarrb);
		else
			return (s->table[i][11] = 4, s->rbrra);
		i++;
	}
	return (i);
}
