/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:09:30 by yel-haya          #+#    #+#             */
/*   Updated: 2024/12/27 20:07:45 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

typedef struct s_node
{
	long			element;
	long			position;
	int				is_it_above;
	int				med;
	int				cost;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_pile
{
	t_node	*head;
}	t_pile;

t_pile	*create_pile(void);
t_node	*create_node(int el);
void	push_swap(int ac, char **av, int which);
int		empty(t_pile *p);
void	add_to_pile(t_pile *p, int el, int position);
void	free_pile(t_pile *a);
int		sorted(t_pile *a);
int		pile_size(t_pile *a);
void	three_el_sort(t_pile **a);
void	give_index(t_pile *a);
char	*jointhatshit(int argc, char **argv);
void	push_back_to_a(t_pile *a, t_pile *b);
int		sorted(t_pile *a);
int		pile_size(t_pile *a);
void	push_a(t_pile *a, t_pile *b, t_node *cheap);
void	push_b(t_pile *a, t_pile *b, t_node *cheap);
void	little_check(t_node *target, t_node *cheap_node, t_pile *a, t_pile *b);
void	push_both(t_pile *a, t_pile *b);
void	set_target_to_b(t_pile *b, t_pile *a);
void	push_to_b(t_pile **a, t_pile *b);
void	calculate_cost(t_pile *a, t_pile *b);
t_node	*set_cheapest(t_pile *a);
void	last_rot(t_pile *a);
void	three_el_sort(t_pile **a);
int		above(t_pile *a);
t_node	*smallest(t_pile *b);
void	give_index(t_pile *a);
void	free_new(char **new, int k);
long	ft_atoii(const char *str);

void	sa(t_pile *a);
void	sb(t_pile *b);
void	ss(t_pile *a, t_pile *b);
void	pa(t_pile *a, t_pile *b);
void	pb(t_pile *a, t_pile *b);
void	ra(t_pile *a);
void	rb(t_pile *b);
void	rr(t_pile *a, t_pile *b);
void	rra(t_pile *a);
void	rrb(t_pile *b);
void	rrr(t_pile *a, t_pile *b);

int		check_errors(int argc, char **argv, int i);

#endif
