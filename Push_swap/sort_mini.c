/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:50:11 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/12 12:47:29 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_three_a(t_stack *s, int *stack, int size)
{
	if (size == 3 && verify_order(s->a, size) == 1)
	{
		if (stack[1] > stack[2] && stack[0] > stack[1])
		{
			swap("sa", s->a, size);
			rotate(s->a, size, "down", 'a');
		}
		if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
			rotate (s->a, size, "up", 'a');
		if (s->a[1] > s->a[2] && stack[0] < stack[1] && stack[0] > stack[2])
			rotate (s->a, size, "down", 'a');
		if (s->a[1] > s->a[2] && stack[0] < stack[1] && stack[0] < stack[2])
		{
			rotate (s->a, size, "down", 'a');
			swap("sa", s->a, size);
		}
	}
	if ((size == 3 || size == 2) && (s->a[0] > s->a[1]))
		swap("sa", s->a, size);
}

void	rank_three_b(t_stack *s, int *stack, int size)
{
	if (size == 3)
	{
		if (stack[1] < stack[2] && stack[0] < stack[1])
		{
			swap("sb", s->b, s->b_size);
			rotate(s->b, s->b_size, "down", 'b');
		}
		if (stack[1] < stack[2] && stack[0] > stack[1] && stack[0] > stack[2])
		{
			swap("sb", s->b, s->b_size);
			rotate (s->b, s->b_size, "up", 'b');
		}
		if (stack[1] > stack[2] && stack[0] < stack[1] && stack[0] > stack[2])
			swap("sb", s->b, s->b_size);
		if (s->b[1] > s->b[2] && stack[0] < stack[1] && stack[0] < stack[2])
			rotate (s->b, size, "up", 'b');
	}
}

void	rank_four_five(t_stack *s)
{
	int	i;

	i = 1;
	if (s->a_size == 5)
		i = 2;
	if ((s->a_size == 5 || s->a_size == 4) && verify_order(s->a, s->a_size))
	{
		while (s->b_size != i && verify_order(s->a, s->a_size) == 1)
		{
			if (f_s_place(s->a, s->a_size) == 0)
				push("pb", s);
			else if (f_s_place(s->a, s->a_size) < 3)
				rotate(s->a, s->a_size, "up", 'a');
			else if (f_s_place(s->a, s->a_size) >= 3)
				rotate(s->a, s->a_size, "down", 'a');
		}
		rank_three_a(s, s->a, s->a_size);
		while (s->b_size != 0)
			push("pa", s);
		free_exit(s, "");
	}
}
