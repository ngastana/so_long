/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:00:00 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/08 17:51:53 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_rank_whatever(t_stack *stack)
{
	int		size;

	size = stack->a_size;
	if (is_circular(stack->a, size) && f_s_place(stack->a, size) > size / 2)
		while (verify_order(stack->a, stack->a_size) == 1)
			rotate(stack->a, stack->a_size, "down", 'a');
	if (is_circular(stack->a, size) && f_s_place(stack->a, size) < size / 2)
		while (verify_order(stack->a, stack->a_size) == 1)
			rotate(stack->a, stack->a_size, "up", 'a');
	if (verify_order(stack->a, stack->a_size) == 0)
		free_exit(stack, "");
	push("pb", stack);
	push("pb", stack);
	push("pb", stack);
	rank_three_b(stack, stack->b, stack->b_size);
}

void	rank_whatever(t_stack *stack)
{
	int	size;
	int	i;

	i = 0;
	size = stack->a_size;
	start_rank_whatever(stack);
	init_table(stack);
	while (stack->a_size > 0)
	{
		highest_b(stack);
		lowest_b(stack);
		fill_table(stack);
		how_much_moviments(stack);
		less_moviments(stack);
	}
	while (stack->b_size > 0)
		push("pa", stack);
	if (is_circular(stack->a, size) && f_s_place(stack->a, size) >= size / 2)
		while (verify_order(stack->a, stack->a_size) == 1)
			rotate(stack->a, stack->a_size, "down", 'a');
	if (is_circular(stack->a, size) && f_s_place(stack->a, size) < size / 2)
		while (verify_order(stack->a, stack->a_size) == 1)
			rotate(stack->a, stack->a_size, "up", 'a');
	free_exit (stack, "");
}
