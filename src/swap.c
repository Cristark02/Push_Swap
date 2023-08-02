/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:49:08 by mmita             #+#    #+#             */
/*   Updated: 2023/08/02 14:47:18 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	aux;

	if (stack == NULL || stack->next == NULL)
		return ;
	aux = stack->value;
	stack->value = stack->next->value;
	stack->next->value = aux;
	aux = stack->index;
	stack->index = stack->next->index;
	stack->next->index = aux;
}

void	sa(t_stack **a)
{
	swap (*a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap (*b);
	write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap (*a);
	swap (*b);
	write (1, "ss\n", 3);
}
