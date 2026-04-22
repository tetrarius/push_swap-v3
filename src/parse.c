/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:44:09 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/20 12:44:12 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check is NUM */
static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Convert to long for limits check INT */
static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/* Dub chack in A */
static int	is_dup(t_node *a, int val)
{
	while (a)
	{
		if (a->value == val)
			return (1);
		a = a->next;
	}
	return (0);
}

/* Validation and add 1 node to A */
static void	add_token(t_env *env, char *token, char **split_arr)
{
	long	val;
	t_node	*new_n;

	if (!is_num(token))
	{
		free_split(split_arr);
		error_exit(env);
	}
	val = ft_atol(token);
	if (val < INT_MIN || val > INT_MAX || is_dup(env->a, (int)val))
	{
		free_split(split_arr);
		error_exit(env);
	}
	new_n = new_node((int)val);
	if (!new_n)
	{
		free_split(split_arr);
		error_exit(env);
	}
	add_node_bottom(&env->a, new_n);
	env->size_a++;
}

/* Parsing arguments */
void	parse_arguments(t_env *env, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split_arr;

	i = 1;
	while (i < argc)
	{
		split_arr = ft_split(argv[i], ' ');
		if (!split_arr || !split_arr[0])
		{
			if (split_arr)
				free_split(split_arr);
			error_exit(env);
		}
		j = 0;
		while (split_arr[j])
		{
			add_token(env, split_arr[j], split_arr);
			j++;
		}
		free_split(split_arr);
		i++;
	}
}