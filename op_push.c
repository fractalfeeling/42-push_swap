/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:14:39 by lwee              #+#    #+#             */
/*   Updated: 2023/02/26 20:14:39 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = *tmp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(*stack_b, *stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(*stack_a, *stack_b);
	ft_putstr("pb\n");
}