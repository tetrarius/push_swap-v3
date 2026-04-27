/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:39:37 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/27 15:34:20 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* move 1st node from src to dest */
static void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	tmp->prev = NULL;
	*dest = tmp;
}

void	pa(t_env *env, bool print)
{
	if (!env->b)
		return ;
	push(&env->b, &env->a);
	env->size_b--;
	env->size_a++;
	env->pa++;
	env->total_ops++;
	if (print && !env->count_only)	//count only
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_env *env, bool print)
{
	if (!env->a)
		return ;
	push(&env->a, &env->b);
	env->size_a--;
	env->size_b++;
	env->pb++;
	env->total_ops++;
	if (print && !env->count_only)  //count only
		ft_putstr_fd("pb\n", 1);
}
