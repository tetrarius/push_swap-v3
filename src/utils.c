/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravakia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:48:13 by aravakia          #+#    #+#             */
/*   Updated: 2026/04/27 14:15:08 by aravakia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Write a STRING to the specified File Descriptor (2 for ERR) */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* Frees a 2D array of STR (after ft_split) */
void	free_split(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

/* Check - is NUMBER */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* Compares 2 STR (for Flags like --bench) */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* Universal ERROR-EXIT function (write Error to stderr) */
void	error_exit(t_env *env)
{
	ft_putstr_fd("Error\n", 2);
	if (env)
	{
		if (env->a)
			free_stack(&env->a);
		if (env->b)
			free_stack(&env->b);
	}
	exit(1);
}
