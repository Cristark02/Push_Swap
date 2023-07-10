/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:23:54 by mmita             #+#    #+#             */
/*   Updated: 2023/07/04 13:47:55 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_stack **a)
{
	rotate (a);
	write (1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate (b);
	write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate (a);
	rotate (b);
	write (1, "rr\n", 3);
}
