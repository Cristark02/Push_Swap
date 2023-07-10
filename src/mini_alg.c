/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:14:45 by mmita             #+#    #+#             */
/*   Updated: 2023/07/08 11:47:02 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	higher_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	mini_sort(t_stack **stack)
{
	int		higher;

	if (is_sorted(*stack))
		return ;
	higher = higher_index(*stack);
	if ((*stack)->index == higher)
		ra(stack);
	else if ((*stack)->next->index == higher)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
