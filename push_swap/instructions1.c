/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:16:45 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 21:07:38 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

void	sa(t_pile *a)
{
	int		tmp;
	t_node	*courant;

	if (empty(a) || a->head == NULL || a->head->next == NULL)
		return ;
	courant = a->head;
	tmp = a->head->element;
	courant = courant->next;
	a->head->element = courant->element;
	courant->element = tmp;
}

void	sb(t_pile *b)
{
	int		tmp;
	t_node	*courant;

	if (empty(b) || b->head == NULL || b->head->next == NULL)
		return ;
	courant = b->head;
	tmp = b->head->element;
	courant = courant->next;
	b->head->element = courant->element;
	courant->element = tmp;
}

void	ss(t_pile *a, t_pile *b)
{
	sa(a);
	sb(b);
}

void	pa(t_pile *a, t_pile *b)
{
	t_node	*tmp;

	if (empty(b) || b->head == NULL)
		return ;
	tmp = a->head;
	a->head = b->head;
	b->head = b->head->next;
	a->head->next = tmp;
}

void	pb(t_pile *a, t_pile *b)
{
	t_node	*tmp;

	if (empty(a) || a->head == NULL)
		return ;
	tmp = b->head;
	b->head = a->head;
	a->head = a->head->next;
	b->head->next = tmp;
}
