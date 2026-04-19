#include "push_swap.h"

/* Меняет местами два верхних элемента стека */
static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_env *env, bool print)
{
	swap(&env->a);
	env->sa++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_env *env, bool print)
{
	swap(&env->b);
	env->sb++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_env *env, bool print)
{
	swap(&env->a);
	swap(&env->b);
	env->ss++;
	env->total_ops++;
	if (print)
		ft_putstr_fd("ss\n", 1);
}
