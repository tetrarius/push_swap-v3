/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:46:47 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/20 11:47:30 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Count Pairs and mistakes */
static void	count_mistakes(t_node *a, int *mistakes, int *total_pairs)
{
	t_node	*i;
	t_node	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			(*total_pairs)++;
			if (i->value > j->value)
				(*mistakes)++;
			j = j->next;
		}
		i = i->next;
	}
}

/* 0.0 - sorted, 1.0 back sorted */
void	calculate_disorder(t_env *env)
{
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!env->a || !env->a->next)
	{
		env->disorder = 0.0;
		return ;
	}
	count_mistakes(env->a, &mistakes, &total_pairs);
	env->disorder = (double)mistakes / total_pairs;
}
