/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:45:11 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/27 13:58:13 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Indexation (0 to N-1) */
void	assign_indices(t_node *a)
{
	t_node	*curr;
	t_node	*cmp;
	int		rank;

	curr = a;
	while (curr)
	{
		rank = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->value < curr->value)
				rank++;
			cmp = cmp->next;
		}
		curr->index = rank;
		curr = curr->next;
	}
}

/* 2. Calculates the numbers of bits for reprezent maximum index */
static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* 3. Do 1 pass for bit i */
static void	process_bit(t_env *env, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((env->a->index >> i) & 1) == 1)
			ra(env, true);
		else
			pb(env, true);
		j++;
	}
	while (env->size_b > 0)
		pa(env, true);
}

/* 4. General function Complex strategy O(n log n) */
void	run_complex(t_env *env)
{
	int	i;
	int	size;
	int	max_bits;

	if (env->size_a == 0)
		return ;
	size = env->size_a;
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		process_bit(env, i, size);
		i++;
	}
}
