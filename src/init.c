/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:02:59 by mmita             #+#    #+#             */
/*   Updated: 2023/08/10 14:04:50 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	assign_index(t_stack *a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*higher;
	int		val;

	while (--stack_size > 0)
	{
		ptr = a;
		val = INT_MIN;
		higher = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > val && ptr->index == 0)
			{
				val = ptr->value;
				higher = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (higher != NULL)
		higher->index = stack_size;
	}
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	n;
	int			i;

	stack_a = NULL;
	n = 0;
	i = 0;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		free(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack (&stack_a);
			write(2, "Error\n", 6);
			exit (1);
		}
		if (i == 0)
		{
			stack_a = new_stack((int)n);
		}
		else
		{
			stack_add_bottom(&stack_a, new_stack((int)n));
		}
		i++;
	}
	free(argv);
	return (stack_a);
}
