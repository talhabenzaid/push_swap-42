/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:13 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 01:25:37 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_stack *n)
{
	int	mid;
	int	i;

	i = 0;
	mid = lst_size(n) / 2;
	while (n)
	{
		n -> index = i;
		if (i <= mid)
			n -> median = true;
		else
			n -> median = false;
		n = n -> next;
		i++;
	}
}

void	target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	close;

	while (a)
	{
		close = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->value < a->value && current->value > close)
			{
				close = current->value;
				target = current;
			}
			current = current->next;
		}
		if (close == LONG_MIN)
			a -> target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = lst_size(a);
	len_b = lst_size(b);
	while (a)
	{
		a -> push_cost = a -> index;
		if (!(a -> median))
			a -> push_cost = len_a - a ->index;
		if (a -> target -> median)
			a -> push_cost += a -> target -> index;
		else
			a -> push_cost += len_b - (a-> target -> index);
		a = a -> next;
	}
}

void	chepest(t_stack *a)
{
	t_stack	*cheapest_node ;
	long	min;

	min = LONG_MAX;
	while (a)
	{
		if (a->push_cost < min)
		{
			min = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	decliration_to_b(t_stack *a, t_stack *b)
{
	position(a);
	position(b);
	target(a, b);
	cost(a, b);
	chepest(a);
}
