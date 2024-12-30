/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:18:53 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 21:20:30 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	sorted(t_pile *a)
{
	t_node	*courant;

	courant = a->head;
	while (courant != NULL && courant->next != NULL)
	{
		if (courant->element > courant->next->element)
			return (0);
		courant = courant->next;
	}
	return (1);
}

int	pile_size(t_pile *a)
{
	t_node	*courant;
	int		count;

	if (a->head == NULL)
		return (0);
	count = 0;
	courant = a->head;
	while (courant != NULL)
	{
		count++;
		courant = courant->next;
	}
	return (count);
}

t_node	*smallest(t_pile *b)
{
	t_node	*courant;
	t_node	*min_node;
	int		min;

	min_node = b->head;
	min = b->head->element;
	courant = b->head;
	while (courant)
	{
		if (courant->element < min)
		{
			min = courant->element;
			min_node = courant;
		}
		courant = courant->next;
	}
	return (min_node);
}

void	push_a(t_pile *a, t_pile *b, t_node *cheap)
{
	while (a->head != cheap->target)
	{
		if (b->head->target->is_it_above == 0)
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
