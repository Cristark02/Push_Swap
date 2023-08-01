/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:54:30 by mmita             #+#    #+#             */
/*   Updated: 2023/08/01 13:31:24 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3)
		mini_sort(a);
	else if (size > 3 && !is_sorted(*a))
		sort (a, b);
}

static char	**parse_split(int argc, char **argv, char **newarg)
{
	int	i;

	i = 0;
	newarg = malloc(argc * sizeof(char *));
	while (argv[i])
	{
		newarg[i] = ft_strdup(argv[i]);
		i++;
	}
		newarg[i] = NULL;
	return (newarg);
}

static char	**parse(int *argc, char **argv, char **newarg)
{
	int		i;
	char	**argaux;

	i = 0;
	if (ft_strchr(argv[1], 32))
	{
		newarg = ft_split(argv[1], 32);
		argaux = ft_split(argv[1], 32);
		while (newarg[i])
		{
			newarg[i + 1] = argaux[i];
			i++;
		}
		newarg[0] = argv[0];
		i = 0;
		while (newarg[i])
			i++;
		*argc = i;
	}
	else
		newarg = parse_split(*argc, argv, NULL);
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
	newarg = parse(&argc, argv, NULL);
	if (!check_args(newarg))
	{
		write(2, "Error: Argumentos incorrectos\n", 30);
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
