/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:45:46 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/27 14:05:00 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1. Calculation of the square root */
static int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= nb && i < 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

/* 2. Move elements to stack B in layers (chunks) */
static void	push_chunks(t_env *env, long step, long limit, int max)
{
	int	i;
	int	curr_size;

	while (env->size_a > 0)
	{
		i = 0;
		curr_size = env->size_a;
		while (i < curr_size)
		{
			if (env->a->index <= limit)
				pb(env, true);
			else
				ra(env, true);
			i++;
		}
		limit += step;
		if (limit > max)
			limit = max;
	}
}

/* 3. Finds the index of maximum el in B */
static int	get_max_index(t_node *b)
{
	int		max;
	int		max_idx;
	int		i;
	t_node	*curr;

	max = b->value;
	max_idx = 0;
	i = 0;
	curr = b;
	while (curr)
	{
		if (curr->value > max)
		{
			max = curr->value;
			max_idx = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_idx);
}

/* 4. Retuns el from B to A in descending order */
static void	push_back_to_a(t_env *env)
{
	int	max_idx;

	while (env->size_b > 0)
	{
		max_idx = get_max_index(env->b);
		if (max_idx <= env->size_b / 2)
		{
			while (max_idx-- > 0)
				rb(env, true);
		}
		else
		{
			while (max_idx++ < env->size_b)
				rrb(env, true);
		}
		pa(env, true);
	}
}

/* 5. General function Medium strategy O(n*sqrt(n)) */
void	run_medium(t_env *env)
{
	int		max_idx;
	int		chunks;
	long	step;

	if (env->size_a == 0)
		return ;
	max_idx = env->size_a - 1;
	chunks = ft_sqrt(env->size_a);
	if (chunks == 0)
		chunks = 1;
	step = env->size_a / chunks;
	push_chunks(env, step, step, max_idx);
	push_back_to_a(env);
}
