/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:07:40 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 21:38:13 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

void	ra(t_pile *a)
{
	t_node	*courant;
	t_node	*sec;

	if (a->head == NULL || a->head->next == NULL)
		return ;
	courant = a->head;
	sec = a->head->next;
	while (courant->next != NULL)
	{
		courant = courant->next;
	}
	courant->next = a->head;
	a->head->next = NULL;
	a->head = sec;
}

void	rb(t_pile *b)
{
	t_node	*courant;
	t_node	*sec;

	if (b->head == NULL || b->head->next == NULL)
		return ;
	courant = b->head;
	sec = b->head->next;
	while (courant->next != NULL)
	{
		courant = courant->next;
	}
	courant->next = b->head;
	b->head->next = NULL;
	b->head = sec;
}

void	rr(t_pile *a, t_pile *b)
{
	ra(a);
	rb(b);
}

void	rra(t_pile *a)
{
	t_node	*courant;
	t_node	*prec;

	if (a->head == NULL || a->head->next == NULL)
		return ;
	courant = a->head;
	while (courant->next != NULL)
	{
		prec = courant;
		courant = courant->next;
	}
	prec->next = NULL;
	courant->next = a->head;
	a->head = courant;
}

void	rrb(t_pile *b)
{
	t_node	*courant;
	t_node	*prec;

	if (b->head == NULL || b->head->next == NULL)
		return ;
	courant = b->head;
	while (courant->next != NULL)
	{
		prec = courant;
		courant = courant->next;
	}
	prec->next = NULL;
	courant->next = b->head;
	b->head = courant;
}
