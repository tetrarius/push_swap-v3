#include "push_swap.h"

/* 1. Инициализация всех счетчиков и указателей */
static void	init_env(t_env *env)
{
	env->a = NULL;
	env->b = NULL;
	env->size_a = 0;
	env->size_b = 0;
	env->bench_flag = false;
	env->strategy = STRAT_ADAPTIVE;
	env->disorder = 0.0;
	env->total_ops = 0;
	env->sa = 0;
	env->sb = 0;
	env->ss = 0;
	env->pa = 0;
	env->pb = 0;
	env->ra = 0;
	env->rb = 0;
	env->rr = 0;
	env->rra = 0;
	env->rrb = 0;
	env->rrr = 0;
}

/* 2. Чтение флагов из начала аргументов */
static int	parse_flags(int argc, char **argv, t_env *env)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			env->bench_flag = true;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			env->strategy = STRAT_SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			env->strategy = STRAT_MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			env->strategy = STRAT_COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			env->strategy = STRAT_ADAPTIVE;
		else
			break ;
		i++;
	}
	return (i);
}

/* 3. Роутер для запуска нужной стратегии сортировки */
static void	execute_strategy(t_env *env)
{
	if (env->strategy == STRAT_SIMPLE)
		run_simple(env);
	else if (env->strategy == STRAT_MEDIUM)
		run_medium(env);
	else if (env->strategy == STRAT_COMPLEX)
		run_complex(env);
	else
		run_adaptive(env);
}

/* 4. Главная функция программы */
int	main(int argc, char **argv)
{
	t_env	env;
	int		start_idx;

	if (argc < 2)
		return (0);
	init_env(&env);
	start_idx = parse_flags(argc, argv, &env);
	if (start_idx >= argc)
		return (0);
	parse_arguments(&env, argc - start_idx + 1, argv + start_idx - 1);
	calculate_disorder(&env);
	if (!is_sorted(env.a))
		execute_strategy(&env);
	print_benchmark(&env);
	free_stack(&env.a);
	return (0);
}
