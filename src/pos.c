/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:56:32 by mmita             #+#    #+#             */
/*   Updated: 2023/07/08 13:18:29 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target(t_stack **a, int b_id, int target_id, int target_pos)
{
	t_stack	*aux;

	aux = *a;
	while (aux)
	{
		if (aux->index > b_id && aux->index < target_id)
		{
			target_id = aux->index;
			target_pos = aux->pos;
		}
		aux = aux->next;
	}
	if (target_id != INT_MAX)
		return (target_pos);
	aux = *a;
	while (aux)
	{
		if (aux->index < target_id)
		{
			target_id = aux->index;
			target_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (target_pos);
}

static void	get_pos(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		target_pos;

	aux = *b;
	get_pos(a);
	get_pos(b);
	target_pos = 0;
	while (aux)
	{
		target_pos = get_target(a, aux->index, INT_MAX, target_pos);
		aux->target_pos = target_pos;
		aux = aux->next;
	}
}

int	get_lower_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_pos(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}
