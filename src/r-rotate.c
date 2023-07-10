/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:40:24 by mmita             #+#    #+#             */
/*   Updated: 2023/07/07 11:49:27 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	aux = *stack;
	*stack = tail;
	(*stack)->next = aux;
	before_tail->next = NULL;
}

void	rra(t_stack **a)
{
	r_rotate (a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	r_rotate (b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate (a);
	r_rotate (b);
	write (1, "rrr\n", 4);
}
