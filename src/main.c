/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:54:30 by mmita             #+#    #+#             */
/*   Updated: 2023/07/08 14:27:02 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Cosas que repasar;
punteros	(*)
listas 		(->)
argumentos	(argc, argv)
*/

static void	print_stack(t_stack *stack)
{
    t_stack	*current = stack;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3)
		mini_sort(a);
	else if (size > 3 && !is_sorted(*a))
		sort (a, b);
	print_stack(*a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
	{
		write(2, "Error: Argumentos incorrectos\n", 30);
		exit (1);
	}
	b = NULL;
	a = fill_stack(argc, argv);
	stack_size = get_stack_size(a);
	assign_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
