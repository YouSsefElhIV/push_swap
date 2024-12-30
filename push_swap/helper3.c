/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:18:19 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/26 01:48:43 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

static int	biggest(t_pile *a)
{
	int		max;
	t_node	*courant;

	max = a->head->element;
	courant = a->head;
	while (courant)
	{
		if (courant->element > max)
			max = courant->element;
		courant = courant->next;
	}
	return (max);
}

void	three_el_sort(t_pile **a)
{
	t_node	*courant;
	int		max;

	courant = (*a)->head;
	max = biggest(*a);
	if (courant->element == max)
	{
		ra(*a);
		ft_printf("ra\n");
	}
	else if (courant->next->element == max)
	{
		rra(*a);
		ft_printf("rra\n");
	}
	if (!sorted(*a))
	{
		sa(*a);
		ft_printf("sa\n");
	}
}

static void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	above(t_pile *a)
{
	t_node	*courant;
	int		i;
	int		pile_len;
	int		*str;

	i = 0;
	courant = a->head;
	pile_len = pile_size(a);
	str = malloc(pile_len * sizeof(int));
	while (courant)
	{
		str[i] = courant->element;
		courant = courant->next;
		i++;
	}
	sort_int_tab(str, pile_len);
	i = str[pile_len / 2];
	courant = a->head;
	while (courant)
	{
		courant->med = i;
		courant = courant->next;
	}
	return (free(str), i);
}

void	give_index(t_pile *a)
{
	t_node	*courant;
	int		i;
	int		median;

	median = pile_size(a) / 2;
	courant = a->head;
	i = 0;
	while (courant)
	{
		courant->position = i;
		if (i <= median)
			courant->is_it_above = 0;
		else
			courant->is_it_above = 1;
		i++;
		courant->target = NULL;
		courant->cheapest = 0;
		courant->cost = 0;
		courant = courant->next;
	}
}
