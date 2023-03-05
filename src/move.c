/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:12:32 by lwee              #+#    #+#             */
/*   Updated: 2023/03/05 18:12:32 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_r(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_rotate_both(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_r(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	do_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			rotate_a(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			reverse_rotate_a(stack_a);
			(*cost_a)++;
		}
	}
}

static void	do_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rotate_b(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			reverse_rotate_b(stack_b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	push_a(stack_a, stack_b);
}
