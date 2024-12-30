/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:11:38 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/30 08:02:27 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include "get_next_line/get_next_line_bonus.h"
#include "../push_swap.h"
#include "checker_bonus.h"

void	error_write(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	the_check(t_pile *a, t_pile *b, char *command)
{
	if (ft_strcmp("sa\n", command) == 0)
		sa(a);
	else if (ft_strcmp("sb\n", command) == 0)
		sb(b);
	else if (ft_strcmp("ra\n", command) == 0)
		ra(a);
	else if (ft_strcmp("rb\n", command) == 0)
		rb(b);
	else if (ft_strcmp("rra\n", command) == 0)
		rra(a);
	else if (ft_strcmp("rrb\n", command) == 0)
		rrb(b);
	else if (ft_strcmp("rr\n", command) == 0)
		rr(a, b);
	else if (ft_strcmp("rrr\n", command) == 0)
		rrr(a, b);
	else if (ft_strcmp("pa\n", command) == 0)
		pa(a, b);
	else if (ft_strcmp("pb\n", command) == 0)
		pb(a, b);
	else if (ft_strcmp("ss\n", command) == 0)
		ss(a, b);
	else
		error_write();
}

void	result_checking(t_pile *a)
{
	t_pile	*b;
	char	*line;

	b = create_pile();
	line = get_next_line(0);
	if (!line)
	{
		if (sorted(a))
			ft_printf("OK\n");
		exit(0);
	}
	while (line != NULL)
	{
		the_check(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (sorted(a) && pile_size(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_pile(b);
}

void	checking(int ac, char **av, int which)
{
	t_pile	*a;
	int		i;

	i = ac;
	a = create_pile();
	while (i >= which)
	{
		add_to_pile(a, ft_atoii(av[i - 1]), 0);
		i--;
	}
	result_checking(a);
	free_pile(a);
}

int	main(int argc, char **argv)
{
	char	**new;
	int		k;

	if (argc == 1)
		return (0);
	argv[1] = jointhatshit(argc, argv);
	k = 0;
	new = ft_split(argv[1], ' ');
	if (!new)
		return (write(2, "Error\n", 6));
	while (new[k])
		k++;
	if (check_errors(k, new, 0) != 0)
		return (free_new(new, k), 0);
	checking(k, &*new, 1);
	free_new(new, k);
}
