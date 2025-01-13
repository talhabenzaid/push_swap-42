/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:36:59 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 19:15:38 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retate_s(t_stack **a, t_stack **b)
{
	retate_n(a, ' ');
	retate_n(b, ' ');
	write(1, "rr\n", 3);
}

void	rev_rotate_n(t_stack **n, char stack)
{
	t_stack	*m;
	t_stack	*tmp;

	if (lst_size(*n) < 2)
		return ;
	tmp = *n;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	m = tmp->next;
	tmp->next = NULL;
	m->next = *n;
	*n = m;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write(1, "rrb\n", 4);
}

void	rev_rotate_s(t_stack **a, t_stack **b)
{
	rev_rotate_n(a, ' ');
	rev_rotate_n(b, ' ');
	write(1, "rrr\n", 4);
}
