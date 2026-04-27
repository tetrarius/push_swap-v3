/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:43:06 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/27 13:44:31 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_env *env, bool print)
{
	rotate(&env->a);
	env->ra++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_env *env, bool print)
{
	rotate(&env->b);
	env->rb++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_env *env, bool print)
{
	rotate(&env->a);
	rotate(&env->b);
	env->rr++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("rr\n", 1);
}
