/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:15:52 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/26 02:14:15 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

static t_node	*get_cheapest_node(t_pile *b)
{
	t_node	*courant_b;
	t_node	*cheapest_node;

	courant_b = b->head;
	while (courant_b)
	{
		if (courant_b->cheapest == 1)
			cheapest_node = courant_b;
		courant_b = courant_b->next;
	}
	return (cheapest_node);
}

void	push_b(t_pile *a, t_pile *b, t_node *cheap)
{
	t_node	*courant_a;
	t_node	*courant_b;

	courant_a = a->head;
	courant_b = b->head;
	while (b->head != cheap)
	{
		if (cheap->is_it_above == 0)
		{
			rb(b);
			ft_printf("rb\n");
		}
		else if (cheap->is_it_above == 1)
		{
			rrb(b);
			ft_printf("rrb\n");
		}
	}
}

void	little_check(t_node *target, t_node *cheap_node, t_pile *a, t_pile *b)
{
	if (target->is_it_above == 0)
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if (target->is_it_above == 1)
	{
		rra(a);
		ft_printf("rra\n");
	}
	if (cheap_node->is_it_above == 0)
	{
		rb(b);
		ft_printf("rb\n");
	}
	else if (cheap_node->is_it_above == 1)
	{
		rrb(b);
		ft_printf("rrb\n");
	}
}

void	push_both(t_pile *a, t_pile *b)
{
	t_node	*target;
	t_node	*cheapest_node;

	cheapest_node = get_cheapest_node(b);
	target = cheapest_node->target;
	while (a->head != target && b->head != cheapest_node)
	{
		if (target->is_it_above == 0 && cheapest_node->is_it_above == 0)
		{
			rr(a, b);
			ft_printf("rr\n");
		}
		else if (target->is_it_above == 1 && cheapest_node->is_it_above == 1)
		{
			rrr(a, b);
			ft_printf("rrr\n");
		}
		else
			little_check(target, cheapest_node, a, b);
	}
}

void	last_rot(t_pile *a)
{
	while (a->head->element != smallest(a)->element)
	{
		if (smallest(a)->is_it_above == 0)
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
		{
			rra(a);
			ft_printf("rra\n");
		}
	}
}
