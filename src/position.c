/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:51:24 by lwee              #+#    #+#             */
/*   Updated: 2023/03/05 18:51:24 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_position(t_stack **stack)
{
	t_stack	*ptr;
	int		i;

	ptr = *stack;
	i = 0;
	while (ptr)
	{
		ptr->pos = i;
		ptr = ptr->next;
		i++;
	}
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*ptr;
	int		lowest_index;
	int		lowest_pos;

	ptr = *stack;
	lowest_index = INT_MAX;
	set_position(stack);
	lowest_pos = ptr->pos;
	while (ptr)
	{
		if (ptr->index < lowest_index)
		{
			lowest_index = ptr->index;
			lowest_pos = ptr->pos;
		}
		ptr = ptr->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **stack_a, int b_index,
	int target_index, int target_pos)
{
	t_stack	*ptr_a;

	ptr_a = *stack_a;
	while (ptr_a)
	{
		if (ptr_a->index > b_index && ptr_a->index < target_index)
		{
			target_index = ptr_a->index;
			target_pos = ptr_a->pos;
		}
		ptr_a = ptr_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	ptr_a = *stack_a;
	while (ptr_a)
	{
		if (ptr_a->index < target_index)
		{
			target_index = ptr_a->index;
			target_pos = ptr_a->pos;
		}
		ptr_a = ptr_a->next;
	}
	return (target_pos);
}

void	set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_b;
	int		target_pos;

	ptr_b = *stack_b;
	set_position(stack_a);
	set_position(stack_b);
	target_pos = 0;
	while (ptr_b)
	{
		target_pos = get_target(stack_a, ptr_b->index, INT_MAX, target_pos);
		ptr_b->target_pos = target_pos;
		ptr_b = ptr_b->next;
	}
}
