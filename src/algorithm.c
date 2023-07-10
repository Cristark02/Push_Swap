/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:36:32 by mmita             #+#    #+#             */
/*   Updated: 2023/07/08 13:17:21 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//rota el stack entero hasta que el numero mas chico sea el primero
static void	shift_stack(t_stack **a)
{
	int	low_pos;
	int	size;

	size = get_stack_size(*a);
	low_pos = get_lower_index_pos(a);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			rra(a);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ra(a);
			low_pos--;
		}	
	}
}

//Empuja todo al stack b excepto los 3 ultimos, del mas peuqeño al mas grande
static void	store_three(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	store_three(a, b);
	mini_sort(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		cheap_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
