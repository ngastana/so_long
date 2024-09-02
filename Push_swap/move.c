/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:24:20 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/07 19:10:35 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_r(t_stack *stack, int pos_mov)
{
	int	i;

	i = 0;
	while (i < stack->table[pos_mov][1])
	{
		rotate(stack->a, stack->a_size, "up", ' ');
		rotate(stack->b, stack->b_size, "up", ' ');
		write (1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < stack->table[pos_mov][2])
	{
		rotate(stack->a, stack->a_size, "up", 'a');
		i++;
	}
	i = 0;
	while (i < stack->table[pos_mov][3])
	{
		rotate(stack->b, stack->b_size, "up", 'b');
		i++;
	}
	push("pb", stack);
}

static void	move_rr(t_stack *stack, int pos_mov)
{
	int	i;

	i = 0;
	while (i < stack->table[pos_mov][4])
	{
		rotate(stack->a, stack->a_size, "down", ' ');
		rotate(stack->b, stack->b_size, "down ", ' ');
		write (1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < stack->table[pos_mov][5])
	{
		rotate(stack->a, stack->a_size, "down", 'a');
		i++;
	}
	i = 0;
	while (i < stack->table[pos_mov][6])
	{
		rotate(stack->b, stack->b_size, "down", 'b');
		i++;
	}
	push("pb", stack);
}

static void	move_rarrb(t_stack *stack, int pos_mov)
{
	int	i;

	i = 0;
	while (i < stack->table[pos_mov][7])
	{
		rotate(stack->a, stack->a_size, "up", 'a');
		i++;
	}
	i = 0;
	while (i < stack->table[pos_mov][8])
	{
		rotate(stack->b, stack->b_size, "down", 'b');
		i++;
	}
	push("pb", stack);
}

static void	move_rbrra(t_stack *stack, int pos_mov)
{
	int	i;

	i = 0;
	while (i < stack->table[pos_mov][9])
	{
		rotate(stack->a, stack->a_size, "down", 'a');
		i++;
	}
	i = 0;
	while (i < stack->table[pos_mov][10])
	{
		rotate(stack->b, stack->b_size, "up", 'b');
		i++;
	}
	push("pb", stack);
}

void	move(t_stack *stack, int pos_mov)
{
	if (stack->table[pos_mov][11] == 1)
		move_r(stack, pos_mov);
	else if (stack->table[pos_mov][11] == 2)
		move_rr(stack, pos_mov);
	else if (stack->table[pos_mov][11] == 3)
		move_rarrb(stack, pos_mov);
	else if (stack->table[pos_mov][11] == 4)
		move_rbrra(stack, pos_mov);
}
