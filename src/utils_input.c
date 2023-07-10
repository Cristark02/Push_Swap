/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:30:05 by mmita             #+#    #+#             */
/*   Updated: 2023/07/10 17:43:21 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

//compreuba si hau elementos duplicados
int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && ft_strncmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//Comprueba la cantidad de ceros
int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '0')
		return (0);
	return (1);
}

/* i se inicializa en 1 en lugar de 0 porque argv[0]
se refiere al nombre del programa en sí mismo*/
int	check_args(int argc, char **argv)
{
	int		i;
	int		zero;
	char	**newarg;

	i = 0;
	if (argc >= 2)
	{
		if (ft_strchr(argv[1], 32))
		{
			newarg = ft_split(argv[1], 32);
			while (newarg[i] != NULL)
				i++;
			argc = i + 1;
			while (i > 0)
			{
				newarg[i] = newarg[i - 1];
				i--;
			}
			newarg[0] = argv[0];
			else
				newarg = argv;
		}
	}

	i = 1;
	zero = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		zero += is_zero(argv[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (have_duplicates(argv))
		return (0);
	return (1);
}
