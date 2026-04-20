/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:20:45 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/20 11:21:48 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1. Находит индекс минимального элемента в стеке A */
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

/* 2. Поднимает минимальный элемент наверх и пушит в B */
static void	push_min_to_b(t_env *env)
{
	int	min_idx;
	int	size;

	min_idx = get_min_index(env->a);
	size = env->size_a;
	if (min_idx <= size / 2)
		while (min_idx-- > 0)
			ra(env, true);
	else
		while (min_idx++ < size)
			rra(env, true);
	pb(env, true);
}

/* 3. Жесткая сортировка для 3 элементов (максимум 2 операции) */
static void	sort_three(t_env *env)
{
	int	first;
	int	second;
	int	third;

	first = env->a->value;
	second = env->a->next->value;
	third = env->a->next->next->value;
	if (first > second && first > third)
		ra(env, true);
	else if (second > first && second > third)
		rra(env, true);
	if (env->a->value > env->a->next->value)
		sa(env, true);
}

/* 4. Маршрутизатор для малых чисел (2-5 элементов) */
static void	sort_mini(t_env *env)
{
	if (env->size_a == 2)
	{
		if (env->a->value > env->a->next->value)
			sa(env, true);
	}
	else if (env->size_a == 3)
		sort_three(env);
	else if (env->size_a <= 5)
	{
		while (env->size_a > 3)
			push_min_to_b(env);
		sort_three(env);
		while (env->size_b > 0)
			pa(env, true);
	}
}

/* 5. Адаптивная стратегия: проверяет размер, затем хаос */
void	run_adaptive(t_env *env)
{
	if (env->size_a <= 5)
		sort_mini(env);
	else if (env->disorder < 0.2)
		run_simple(env);
	else if (env->disorder < 0.5)
		run_medium(env);
	else
		run_complex(env);
}
