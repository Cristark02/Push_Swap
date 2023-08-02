/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:55:35 by mmita             #+#    #+#             */
/*   Updated: 2023/08/01 16:12:35 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*Inicializacion*/
t_stack		*fill_stack(int argc, char **argv);
void		assign_index(t_stack *a, int stack_size);

/*Algoritmos*/
int			is_sorted(t_stack *stack);
void		mini_sort(t_stack **stack);
void		sort(t_stack **a, t_stack **b);

/*Posiciones*/
void		get_target_position(t_stack **a, t_stack **b);
int			get_lower_index_pos(t_stack **stack);

/*Costes*/
void		get_cost(t_stack **a, t_stack **b);
void		cheap_move(t_stack **a, t_stack **b);
void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/*Movimientos*/
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rra(t_stack **a);
void		rrr(t_stack **a, t_stack **b);

/*Stacks*/
t_stack		*new_stack(int value);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
int			get_stack_size(t_stack	*stack);
void		stack_add_bottom(t_stack **stack, t_stack *new);

/*Utiles*/
void		free_stack(t_stack **stack);
int			positive(int nb);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);

/*Comprobaciones de Entradas*/
int			check_args(char **argv);
int			ft_strncmp(const char *s1, const char *s2);
int			is_digit(char c);
int			is_sign(char c);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
size_t		ft_count_word(const char *str, char c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);

#endif