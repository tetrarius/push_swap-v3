#include "push_swap.h"

/* Вспомогательная функция для вывода чисел в stderr */
static void	put_num_stderr(int n)
{
	char	c;
	long	num;

	num = n;
	if (num < 0)
	{
		write(2, "-", 1);
		num = -num;
	}
	if (num >= 10)
		put_num_stderr(num / 10);
	c = (num % 10) + '0';
	write(2, &c, 1);
}

/* Вывод процентов (хаоса) с двумя знаками после запятой */
static void	print_disorder(double disorder)
{
	int		int_part;
	int		dec_part;
	double	percent;

	percent = disorder * 100.0;
	int_part = (int)percent;
	dec_part = (int)((percent - int_part) * 100.0 + 0.5);
	if (dec_part >= 100)
	{
		int_part++;
		dec_part = 0;
	}
	put_num_stderr(int_part);
	write(2, ".", 1);
	if (dec_part < 10)
		write(2, "0", 1);
	put_num_stderr(dec_part);
	write(2, "%\n", 2);
}

/* Первая часть метрик (swap и push) */
static void	print_ops_part1(t_env *env)
{
	ft_putstr_fd("[bench] sa: ", 2);
	put_num_stderr(env->sa);
	ft_putstr_fd(" sb: ", 2);
	put_num_stderr(env->sb);
	ft_putstr_fd(" ss: ", 2);
	put_num_stderr(env->ss);
	ft_putstr_fd(" pa: ", 2);
	put_num_stderr(env->pa);
	ft_putstr_fd(" pb: ", 2);
	put_num_stderr(env->pb);
	write(2, "\n", 1);
}

/* Вторая часть метрик (rotate и reverse rotate) */
static void	print_ops_part2(t_env *env)
{
	ft_putstr_fd("[bench] ra: ", 2);
	put_num_stderr(env->ra);
	ft_putstr_fd(" rb: ", 2);
	put_num_stderr(env->rb);
	ft_putstr_fd(" rr: ", 2);
	put_num_stderr(env->rr);
	ft_putstr_fd(" rra: ", 2);
	put_num_stderr(env->rra);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] rrb: ", 2);
	put_num_stderr(env->rrb);
	ft_putstr_fd(" rrr: ", 2);
	put_num_stderr(env->rrr);
	write(2, "\n", 1);
}

/* Главная функция бенчмарка */
void	print_benchmark(t_env *env)
{
	if (!env->bench_flag)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(env->disorder);
	if (env->strategy == STRAT_ADAPTIVE)
	{
		if (env->disorder < 0.2)
			ft_putstr_fd("[bench] strategy: Adaptive / O(n^2)\n", 2);
		else if (env->disorder < 0.5)
			ft_putstr_fd("[bench] strategy: Adaptive / O(n*sqrt(n))\n", 2);
		else
			ft_putstr_fd("[bench] strategy: Adaptive / O(n log n)\n", 2);
	}
	else if (env->strategy == STRAT_SIMPLE)
		ft_putstr_fd("[bench] strategy: Simple / O(n^2)\n", 2);
	else if (env->strategy == STRAT_MEDIUM)
		ft_putstr_fd("[bench] strategy: Medium / O(n*sqrt(n))\n", 2);
	else if (env->strategy == STRAT_COMPLEX)
		ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	put_num_stderr(env->total_ops);
	write(2, "\n", 1);
	print_ops_part1(env);
	print_ops_part2(env);
}
