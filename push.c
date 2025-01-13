/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:54 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/09 23:16:51 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		{
			if (top_node->median)
				retate_n(stack, stack_name);
			else
				rev_rotate_n(stack, stack_name);
		}	
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->median && cheapest_node->target->median)
	{
		while (*b != cheapest_node->target && *a != cheapest_node)
			retate_s(a, b);
		position(*a);
		position(*b);
	}
	else if (!(cheapest_node->median) && !(cheapest_node->target->median))
	{
		while (*b != cheapest_node->target && *a != cheapest_node)
			rev_rotate_s(a, b);
		position(*a);
		position(*b);
	}
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target, 'b');
	push_n(a, b, 'b');
}

void	push_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	push_n(b, a, 'a');
}
