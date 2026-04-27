/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:37:56 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/27 15:04:03 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

/* --- ENUMS --- */
typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

/* --- STRUCTURES --- */
// Stacks
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// GENERAL ENVIRONMENT
typedef struct s_env
{
	t_node		*a;
	t_node		*b;
	int			size_a;
	int			size_b;

	bool		bench_flag;
	bool		count_only;
	t_strategy	strategy;
	double		disorder;

	// calc --bench
	int			total_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_env;

/* --- PROTOTYPES --- */

/* utils.c */
void	ft_putstr_fd(char *s, int fd);
void	error_exit(t_env *env);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	free_split(char **strs);

/* split.c */
char	**ft_split(char const *s, char c);

/* parse.c */
void	parse_arguments(t_env *env, int argc, char **argv);

/* stack_utils.c */
t_node	*new_node(int value);
void	add_node_bottom(t_node **stack, t_node *node);
void	free_stack(t_node **stack);
bool	is_sorted(t_node *stack);

/* disorder.c */
void	calculate_disorder(t_env *env);

/* operations_*.c */
void	sa(t_env *env, bool print);
void	sb(t_env *env, bool print);
void	ss(t_env *env, bool print);
void	pa(t_env *env, bool print);
void	pb(t_env *env, bool print);
void	ra(t_env *env, bool print);
void	rb(t_env *env, bool print);
void	rr(t_env *env, bool print);
void	rra(t_env *env, bool print);
void	rrb(t_env *env, bool print);
void	rrr(t_env *env, bool print);

/* strategies */
void	run_simple(t_env *env);
void	run_medium(t_env *env);
void	run_complex(t_env *env);
void	run_adaptive(t_env *env);
void	assign_indices(t_node *a);

/* benchmark.c */
void	print_benchmark(t_env *env);

#endif
