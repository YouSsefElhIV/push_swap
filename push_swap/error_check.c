/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:03:36 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/26 21:39:37 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

int	isduplicate(char *arg, int current, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i != current && (ft_atoi(arg) - ft_atoi(argv[i]) == 0))
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(int argc, char **argv, int i)
{
	int		j;
	long	num;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32)
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			num = ft_atoii(argv[i]);
			if (argv[i][j] < '0' || argv[i][j] > '9'
			|| num > 2147483647 || num < -2147483648)
				return (write(2, "Error\n", 6), exit(1), 0);
			j++;
		}
		if (isduplicate(argv[i], i, argv, argc))
			return (write(2, "Error\n", 6), exit(1), 0);
		i++;
	}
	return (0);
}
