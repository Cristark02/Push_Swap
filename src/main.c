/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:54:30 by mmita             #+#    #+#             */
/*   Updated: 2023/08/10 14:15:55 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3)
		mini_sort(a);
	else if (size > 3 && !is_sorted(*a))
		sort (a, b);
}

static char	**parse_split(int *argc, char **argv, char **newarg)
{
	int	i;

	i = 0;
	newarg = malloc(*argc * sizeof(char *));
	while (argv[i])
	{
		newarg[i] = ft_strdup(argv[i]);
		i++;
	}
	newarg[i] = NULL;
	*argc = *argc - 1;
	return (newarg);
}

static char	**parse(int *argc, char **argv, char **newarg)
{
	int		i;

	i = 0;
	if (*argc == 2 && ft_strchr(argv[0], 32))
	{
		newarg = ft_split(argv[0], 32);
		if (!newarg)
			return (NULL);
		i = 0;
		while (newarg[i])
			i++;
		*argc = i;
	}
	else
		newarg = parse_split(argc, argv, NULL);
	return (newarg);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**newarg;
	int		stack_size;

	if (argc < 2)
		return (0);
	newarg = parse(&argc, &argv[1], NULL);
	if (argc == 0 || !newarg || !check_args(newarg))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	b = NULL;
	a = fill_stack(argc, newarg);
	stack_size = get_stack_size(a);
	assign_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
