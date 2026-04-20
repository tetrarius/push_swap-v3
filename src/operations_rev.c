/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:40:24 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/20 12:42:43 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Сдвигает все элементы стека вниз на один. Последний становится первым. */
static void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_env *env, bool print)
{
	rev_rotate(&env->a);
	env->rra++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_env *env, bool print)
{
	rev_rotate(&env->b);
	env->rrb++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_env *env, bool print)
{
	rev_rotate(&env->a);
	rev_rotate(&env->b);
	env->rrr++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
