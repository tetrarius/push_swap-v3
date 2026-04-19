#include "push_swap.h"

/*
** Адаптивная стратегия: выбирает алгоритм в зависимости от хаоса.
** < 20% хаоса -> Simple O(n^2)
** 20% - 49% хаоса -> Medium O(n*sqrt(n))
** >= 50% хаоса -> Complex O(n log n)
*/
void	run_adaptive(t_env *env)
{
	if (env->disorder < 0.2)
		run_simple(env);
	else if (env->disorder < 0.5)
		run_medium(env);
	else
		run_complex(env);
}
