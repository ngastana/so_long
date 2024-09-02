/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:59:29 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/12 15:22:11 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_stack *stack, char *msg)
{
	int	i;

	i = -1;
	if (msg)
		while (msg[i++])
			write (2, &msg[i], 1);
	if (stack != NULL)
	{
		if (stack->a != NULL)
			free(stack->a);
		if (stack->b != NULL)
			free(stack->b);
		if (stack->table != NULL)
		{
			i = 0;
			while (stack->table[i] != NULL)
			{
				free(stack->table[i]);
				i++;
			}
			free (stack->table);
		}
		free (stack);
	}
	exit(1);
}
