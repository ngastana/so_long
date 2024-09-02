/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:59:20 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/12 15:21:25 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;
	size_t	i;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc > 1)
	{
		check_arguments(argv, argc);
		stack = malloc (sizeof(t_stack) * 1);
		if (!stack)
			exit(1);
		ft_memset(stack, 0, sizeof(t_stack));
		init_stacks(stack, argc, argv);
		fill_stack(stack, argc, argv);
		check_duplicate(stack);
		rank_three_a(stack, stack->a, stack->a_size);
		if (stack->a_size == 3 || stack->a_size == 2)
			free_exit (stack, "");
		rank_four_five(stack);
		rank_whatever(stack);
		write (2, "\n", 1);
	}
	return (0);
}
