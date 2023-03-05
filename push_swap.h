/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:06:46 by lwee              #+#    #+#             */
/*   Updated: 2023/02/26 19:06:46 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
void		free_stack(t_stack **stack);

int			check_input(char **argv);

void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_s(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_r(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);

t_stack		*stack_get_bottom(t_stack *stack);
t_stack		*stack_get_before_bottom(t_stack *stack);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			stack_get_size(t_stack *stack);

t_stack		*stack_new_element(int value);
t_stack		*stack_fill(int argc, char **argv);
void		assign_index(t_stack *stack_a, int stack_size);

int			get_lowest_index_position(t_stack **stack);
void		set_target_position(t_stack **stack_a, t_stack **stack_b);

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void		do_move(t_stack **stack_a, t_stack **stack_b,
				int cost_a, int cost_b);

int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

#endif
