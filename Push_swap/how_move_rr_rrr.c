/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_move_rr_rrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 08:57:05 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/02 12:01:36 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	how_move_rr(t_stack *stack, int i)
{
	if (stack->table[i][2] > 0 && stack->table[i][3] > 0)
	{
		if (stack->table[i][2] >= stack->table[i][3])
		{
			stack->table[i][1] = stack->table[i][3];
			stack->table[i][2] = stack->table[i][2] - stack->table[i][3];
			stack->table[i][3] = 0;
		}
		else if (stack->table[i][2] < stack->table[i][3])
		{
			stack->table[i][1] = stack->table[i][2];
			stack->table[i][3] = stack->table[i][3] - stack->table[i][2];
			stack->table[i][2] = 0;
		}
	}
}

static void	how_move_rrr(t_stack *stack, int i)
{
	if (stack->table[i][5] > 0 && stack->table[i][6] > 0)
	{
		if (stack->table[i][5] > stack->table[i][6])
		{
			stack->table[i][4] = stack->table[i][6];
			stack->table[i][5] = stack->table[i][5] - stack->table[i][6];
			stack->table[i][6] = 0;
		}
		else
		{
			stack->table[i][4] = stack->table[i][5];
			stack->table[i][6] = stack->table[i][6] - stack->table[i][5];
			stack->table[i][5] = 0;
		}
	}
}

static int	movements_num(t_stack *s, int i)
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

void	how_much_moviments(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size)
	{
		how_move_rr(stack, i);
		how_move_rrr(stack, i);
		stack->table[i][0] = movements_num(stack, i);
		i++;
	}
}

void	less_moviments(t_stack *stack)
{
	int	i;

	stack->pos_mov = 0;
	i = 0;
	while (i < stack->a_size)
	{
		if (stack->table[stack->pos_mov][0] > stack->table[i][0])
			stack->pos_mov = i;
		i++;
	}
	move(stack, stack->pos_mov);
}
