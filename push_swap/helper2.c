/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:17:08 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 22:26:48 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	set_target_for_node(t_node *courant_b, t_pile *a)
{
	long	calc;
	t_node	*courant_a;
	t_node	*target_node;

	calc = LONG_MAX;
	courant_a = a->head;
	while (courant_a)
	{
		if (courant_a->element > courant_b->element
			&& courant_a->element < calc)
		{
			calc = courant_a->element;
			target_node = courant_a;
		}
		courant_a = courant_a->next;
	}
	if (calc == LONG_MAX)
		courant_b->target = smallest(a);
	else
		courant_b->target = target_node;
}

void	set_target_to_b(t_pile *b, t_pile *a)
{
	t_node	*courant_b;

	courant_b = b->head;
	while (courant_b)
	{
		set_target_for_node(courant_b, a);
		courant_b = courant_b->next;
	}
}

void	push_to_b(t_pile **a, t_pile *b)
{
	int	mediant;

	mediant = above(*a);
	while (pile_size(*a) != 3 && !sorted(*a))
	{
		if ((*a)->head->element < mediant)
		{
			pb(*a, b);
			if (pile_size(b) > 1)
			{
				rb(b);
				ft_printf("pb\nrb\n");
			}
			else
				ft_printf("pb\n");
		}
		else if ((*a)->head->element >= mediant)
		{
			pb(*a, b);
			ft_printf("pb\n");
		}
	}
}

void	calculate_cost(t_pile *a, t_pile *b)
{
	int		len_a;
	int		len_b;
	t_node	*courant;

	len_a = pile_size(a);
	len_b = pile_size(b);
	courant = b->head;
	while (courant)
	{
		if (courant->is_it_above == 0)
			courant->cost = courant->position;
		else
			courant->cost = len_b - courant->position;
		if (courant->target->is_it_above == 0)
			courant->cost += courant->target->position;
		else
			courant->cost = courant->cost + (len_a - courant->target->position);
		courant = courant->next;
	}
}

t_node	*set_cheapest(t_pile *a)
{
	long	cheapest;
	t_node	*courant;
	t_node	*cheapest_node;

	courant = a->head;
	cheapest = LONG_MAX;
	while (courant)
	{
		if (courant->cost < cheapest)
		{
			cheapest = courant->cost;
			cheapest_node = courant;
		}
		courant = courant->next;
	}
	courant = a->head;
	while (courant)
	{
		if (courant != cheapest_node)
			courant->cheapest = 0;
		courant = courant->next;
	}
	cheapest_node->cheapest = 1;
	return (cheapest_node);
}
