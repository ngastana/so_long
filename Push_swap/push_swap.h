/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:26:16 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/12 14:13:10 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write
# include <stdlib.h> //malloc
# include <stdio.h> //printf
# include <limits.h>
# include <math.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		**table;
	int		a_size;
	int		b_size;
	int		highest_b;
	int		lowest_b;
	int		r;
	int		rr;
	int		rarrb;
	int		rbrra;
	int		pos_mov;
}			t_stack;

/*split*/
char	**ft_split(char *str);

/*putstr*/
void	putstr(char *s);

/*stacks*/
void	init_stacks(t_stack *stack, int argc, char **argv);
void	fill_stack(t_stack *stack, int argc, char **argv);

/*utils*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
long	atoi_long(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

/*moviments*/
void	push(char *str, t_stack *stack);
void	swap(char *str, int *array, int size);
void	rotate(int *array, int size, char *direction, char stack);

/*verify_find*/
int		verify_order(int *array, int size);
int		f_s_place(int *stack, int size);

/*sort*/
void	rank_three_a(t_stack *s, int *stack, int size);
void	rank_three_b(t_stack *s, int *stack, int size);
void	rank_four_five(t_stack *stack);

/*check*/
void	check_arguments(char **argv, int argc);
void	check_duplicate(t_stack *stack);
int		is_circular(int *arr, int size);
void	check_phrase(t_stack *stack, char *argv);

/*free and exit*/
void	free_exit(t_stack *s, char *msg);

/*info table*/
void	highest_b(t_stack *stack);
void	lowest_b(t_stack *stack);
int		position_b(t_stack *stack, int i);

/*table*/
void	init_table(t_stack	*stack);
void	fill_table(t_stack *stack);

/*how_move_rr_rrr*/
void	how_much_moviments(t_stack *stack);
void	less_moviments(t_stack *stack);

/*move*/
void	move(t_stack *stack, int i);

/*sort_max*/
void	rank_whatever(t_stack *stack);

/*main*/
int		main(int argc, char **argv);

#endif