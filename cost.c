/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:38:48 by lwee              #+#    #+#             */
/*   Updated: 2023/03/05 17:38:48 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	int		size_a;
	int		size_b;

	ptr_a = *stack_a;
	ptr_b = *stack_b;
	size_a = stack_get_size(ptr_a);
	size_b = stack_get_size(ptr_b);
	while (ptr_b)
	{
		ptr_b->cost_b = ptr_b->pos;
		if (ptr_b->pos > size_b / 2)
			ptr_b->cost_b = (size_b - ptr_b->pos) * -1;
		ptr_b->cost_a = ptr_b->target_pos;
		if (ptr_b->target_pos > size_a / 2)
			ptr_b->cost_a = (size_a - ptr_b->target_pos) * -1;
		ptr_b = ptr_b->next;
	}
}

static int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	ptr = *stack_b;
	cheapest = INT_MAX;
	while (ptr)
	{
		if (nb_abs(ptr->cost_a) + nb_abs(ptr->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(ptr->cost_b) + nb_abs(ptr->cost_a);
			cost_a = ptr->cost_a;
			cost_b = ptr->cost_b;
		}
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
