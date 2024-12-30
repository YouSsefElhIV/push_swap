/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:23:03 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/26 02:02:13 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

t_node	*create_node(int el)
{
	t_node	*n;

	n = (t_node *) malloc (sizeof(t_node));
	if (n == NULL)
		return (NULL);
	n->element = el;
	n->next = NULL;
	return (n);
}

t_pile	*create_pile(void)
{
	t_pile	*p;

	p = (t_pile *) malloc (sizeof(t_pile));
	if (p == NULL)
		return (NULL);
	p->head = NULL;
	return (p);
}

int	empty(t_pile *p)
{
	return (p == NULL);
}

void	add_to_pile(t_pile *p, int el, int position)
{
	t_node	*new;

	new = create_node(el);
	if (empty(p) == 1)
		p->head = new;
	else
	{
		new->next = p->head;
		p->head = new;
	}
	p->head->position = position;
}

void	free_pile(t_pile *a)
{
	t_node	*courant;
	t_node	*next;

	if (a == NULL)
		return ;
	courant = a->head;
	while (courant != NULL)
	{
		next = courant->next;
		free(courant);
		courant = next;
	}
	a->head = NULL;
	free(a);
	a = NULL;
}
