/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:58:04 by mmita             #+#    #+#             */
/*   Updated: 2023/08/04 18:17:23 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *a;
	aux_b = *b;
	size_a = get_stack_size(aux_a);
	size_b = get_stack_size(aux_b);
	while (aux_b)
	{
		aux_b->cost_b = aux_b->pos;
		if (aux_b->pos > size_b / 2)
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		aux_b->cost_a = aux_b->target_pos;
		if (aux_b->target_pos > size_a / 2)
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		aux_b = aux_b->next;
	}
}

void	cheap_move(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		cheap;
	int		cost_a;
	int		cost_b;

	aux = *b;
	cheap = INT_MAX;
	while (aux)
	{
		if (positive(aux->cost_a) + positive(aux->cost_b) < positive(cheap))
		{
			cheap = positive(aux->cost_a) + positive(aux->cost_b);
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
		}
		aux = aux->next;
	}
	move(a, b, cost_a, cost_b);
}
