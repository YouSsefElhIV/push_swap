/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:17:09 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 21:52:06 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

void	rrr(t_pile *a, t_pile *b)
{
	rra(a);
	rrb(b);
}

static int	spaces_check(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoii(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	res2;

	res = 0;
	res2 = 0;
	i = 0;
	sign = spaces_check(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		res2 = res * 10 + (str[i] - 48);
		i++;
		if (res2 > INT_MAX || res2 < INT_MIN)
			return (INT_MAX + (long)1);
		res = res2;
	}
	if (str[i] != '\0' && ft_isdigit(str[++i]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return ((res * sign));
}

static char	*join_with_space(char *result, char *word)
{
	char	*temp;

	temp = ft_strjoin(result, word);
	if (!temp)
		return (free(result), NULL);
	free(result);
	return (temp);
}

char	*jointhatshit(int argc, char **argv)
{
	int		i;
	char	*result;
	int		j;

	result = malloc(1);
	if (!result)
		return (NULL);
	1 && (result[0] = '\0', i = 0, j = 0);
	while (++i < argc)
	{
		while (argv[i][j] == 32)
			j++;
		if (argv[i][j] == '\0')
			1 && write(2, "Error\n", 6), exit(1);
		result = join_with_space(result, argv[i]);
		if (!result)
			return (NULL);
		if (i < argc - 1)
		{
			result = join_with_space(result, " ");
			if (!result)
				return (NULL);
		}
	}
	return (result);
}
