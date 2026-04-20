/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:46:01 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/20 12:46:03 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Находит позицию (индекс) минимального элемента в стеке A */
static int	get_min_index(t_node *a)
{
	int		min;
	int		min_idx;
	int		i;
	t_node	*curr;

	min = a->value;
	min_idx = 0;
	i = 0;
	curr = a;
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			min_idx = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_idx);
}

/* Крутит стек A так, чтобы минимальный элемент оказался на самом верху.
   Выбирает кратчайший путь: ra или rra. */
static void	rotate_a_to_min(t_env *env, int min_index)
{
	int	size;

	size = env->size_a;
	if (min_index <= size / 2)
	{
		while (min_index > 0)
		{
			ra(env, true);
			min_index--;
		}
	}
	else
	{
		while (min_index < size)
		{
			rra(env, true);
			min_index++;
		}
	}
}

/* Главная функция O(n^2) стратегии */
void	run_simple(t_env *env)
{
	int	min_idx;

	while (env->size_a > 0)
	{
		min_idx = get_min_index(env->a);
		rotate_a_to_min(env, min_idx);
		pb(env, true);
	}
	while (env->size_b > 0)
	{
		pa(env, true);
	}
}
