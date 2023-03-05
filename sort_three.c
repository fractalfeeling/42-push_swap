/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:22:54 by lwee              #+#    #+#             */
/*   Updated: 2023/03/02 19:22:54 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = get_highest_index(*stack);
	if ((*stack)->index == highest)
		rotate_a(stack);
	else if ((*stack)->next->index == highest)
		reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
}
