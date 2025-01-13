/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:19 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 01:21:07 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *a)
{
	t_stack	*biggest;
	t_stack	*current;

	biggest = a;
	current = a -> next;
	while (current)
	{
		if (biggest->value > current->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	target_again(t_stack *a, t_stack *b)
{
	t_stack		*current;
	t_stack		*target;
	long		close;

	while (b)
	{
		close = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < close)
			{
				close = current->value;
				target = current;
			}
			current = current->next;
		}
		if (close == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	decliration_to_a(t_stack *a, t_stack *b)
{
	position(a);
	position(b);
	target_again(a, b);
}

void	min_to_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->median)
			retate_n(a, 'a');
		else
			rev_rotate_n(a, 'a');
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = lst_size(*a);
	if (len-- > 3 && is_not_sort(*a))
		push_n(a, b, 'b');
	if (len-- > 3 && is_not_sort(*a))
		push_n(a, b, 'b');
	while (len-- > 3 && is_not_sort(*a))
	{
		decliration_to_b(*a, *b);
		push_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		decliration_to_a(*a, *b);
		push_to_a(a, b);
	}
	position(*a);
	min_to_top(a);
}
