/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:54:30 by mmita             #+#    #+#             */
/*   Updated: 2023/08/07 16:20:58 by mmita            ###   ########.fr       */
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
	if (ft_strchr(argv[1], 32) && *argc == 2)
	{
		newarg = ft_split(argv[1], 32);
		argaux = ft_split(argv[1], 32);
		while (argaux[i])
		{
			free(newarg[i + 1]);
			newarg[i + 1] = ft_strdup(argaux[i]);
			i++;
		}
		free(newarg[0]);
		newarg[0] = ft_strdup(argv[0]);
		i = 0;
		while (newarg[i])
			i++;
		*argc = i;
		free_char(argaux);
	}
	else
		newarg = parse_split(*argc, argv, NULL);
	return (newarg);
}

void	ft_leaks(void)
{
	system ("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**newarg;
	int		stack_size;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	atexit(ft_leaks);
	newarg = parse(&argc, argv, NULL);
	if (argc == 1 || !check_args(newarg))
	{
		write(2, "Error\n", 6);
		free_char(newarg);
		exit (1);
	}
	b = NULL;
	a = fill_stack(argc, newarg);
	//free_char(newarg);
	stack_size = get_stack_size(a);
	assign_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
