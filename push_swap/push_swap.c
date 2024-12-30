/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:29:18 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 21:53:05 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	push_back_to_a(t_pile *a, t_pile *b)
{
	t_node	*courant;
	t_node	*courant_b;
	t_node	*cheap;

	courant_b = b->head;
	while (b->head)
	{
		give_index(a);
		give_index(b);
		set_target_to_b(b, a);
		calculate_cost(a, b);
		cheap = set_cheapest(b);
		push_both(a, b);
		push_b(a, b, cheap);
		courant = a->head;
		push_a(a, b, cheap);
		pa(a, b);
		ft_printf("pa\n");
	}
	give_index(a);
	last_rot(a);
}

void	sort_pile(t_pile **a)
{
	t_pile	*b;

	b = create_pile();
	push_to_b(a, b);
	three_el_sort(a);
	push_back_to_a(*a, b);
	free_pile(b);
}

void	push_swap(int ac, char **av, int which)
{
	t_pile	*a;

	a = create_pile();
	while (ac >= which)
	{
		add_to_pile(a, ft_atoii(av[ac - 1]), 0);
		ac--;
	}
	if (!sorted(a))
	{
		if (pile_size(a) == 2)
		{
			if (!sorted(a))
			{
				sa(a);
				ft_printf("sa\n");
			}
		}
		else if (pile_size(a) == 3)
			three_el_sort(&a);
		else
			sort_pile(&a);
	}
	free_pile(a);
}

void	free_new(char **new, int k)
{
	while (k > 0)
		free(new[--k]);
	free(new);
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
	push_swap(k, &*new, 1);
	free_new(new, k);
}
