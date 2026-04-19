#include "push_swap.h"

/* Выводит строку в указанный файловый дескриптор (2 для ошибок) */
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

/* Освобождает двумерный массив строк (после ft_split) */
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

/* Проверяет, является ли символ цифрой */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* Сравнивает две строки (нужно для обработки флагов вроде --bench) */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* Универсальная функция выхода с ошибкой по сабджекту (пишет Error в stderr) */
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
