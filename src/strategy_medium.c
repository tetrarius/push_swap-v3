#include "push_swap.h"

/* 1. Приближенное вычисление квадратного корня */
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

/* 2. Перенос элементов в B слоями (чанками) */
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
			if (env->a->value <= limit)
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

/* 3. Ищет индекс максимального элемента в стеке B */
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

/* 4. Возвращает элементы из B в A по убыванию */
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

/* 5. Главная функция стратегии Medium O(n*sqrt(n)) */
void	run_medium(t_env *env)
{
	int		min;
	int		max;
	int		chunks;
	long	step;
	t_node	*a;

	if (env->size_a == 0)
		return ;
	a = env->a;
	min = a->value;
	max = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	chunks = ft_sqrt(env->size_a);
	if (chunks == 0)
		chunks = 1;
	step = (long)(max - min) / chunks;
	push_chunks(env, step, min + step, max);
	push_back_to_a(env);
}
