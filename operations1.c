/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:25 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 19:15:31 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_stack *node)
{
	int	i;

	i = 0;
	if (!node)
		return (0);
	while (node)
	{
		i++;
		node = node -> next;
	}
	return (i);
}

void	swap_n(t_stack **n, char stack)
{
	t_stack	*tmp;

	if (*n && (*n)-> next)
	{
		tmp = *n;
		*n = (*n)-> next;
		tmp->next = (*n)->next;
		(*n)-> next = tmp;
	}
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write(1, "sb\n", 3);
}

void	swap_s(t_stack **a, t_stack **b)
{
	swap_n(a, ' ');
	swap_n(b, ' ');
	write(1, "ss\n", 3);
}

void	push_n(t_stack **n1, t_stack **n2, char stack)
{
	t_stack	*tmp;

	if (*n1)
	{
		tmp = *n1;
		*n1 = (*n1)->next;
		tmp->next = *n2;
		*n2 = tmp;
	}
	if (stack == 'a')
		write(1, "pa\n", 3);
	else if (stack == 'b')
		write(1, "pb\n", 3);
}

void	retate_n(t_stack **n, char stack)
{
	t_stack	*m;
	t_stack	*tmp;

	if (lst_size(*n) < 2)
		return ;
	m = *n;
	tmp = *n;
	while (tmp->next)
		tmp = tmp->next;
	*n = m->next;
	m->next = NULL;
	tmp->next = m;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write(1, "rb\n", 3);
}
