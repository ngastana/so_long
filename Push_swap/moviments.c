/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:48:42 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/07 20:30:41 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_b(t_stack *stack)
{
	int	i;

	if (stack->a > 0)
	{
		i = stack->b_size;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->a_size - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a_size--;
		stack->b_size++;
	}
}

static void	ft_push_a(t_stack *stack)
{
	int	i;

	i = stack->a_size;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->a_size++;
	stack->b_size--;
}

void	push(char *str, t_stack *stack)
{
	if (str[1] == 'a')
		ft_push_a(stack);
	else if (str[1] == 'b')
		ft_push_b(stack);
	putstr(str);
}

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	putstr(str);
}

void	rotate(int *array, int size, char *direction, char stack)
{
	int	tmp;

	if (size < 0)
		return ;
	if (direction[0] == 'u')
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (direction[0] == 'd')
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		if (direction[4] != ' ')
			write(1, "r", 1);
		write(1, "r", 1);
	}
	if (stack != ' ')
	{
		write (1, &stack, 1);
		write (1, "\n", 1);
	}
}
