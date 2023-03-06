/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:40:59 by lwee              #+#    #+#             */
/*   Updated: 2023/03/06 13:06:34 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = stack_get_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
}

static void	final_sort(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = stack_get_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			reverse_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		set_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		final_sort(stack_a);
}
