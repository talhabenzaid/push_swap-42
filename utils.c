/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:06:06 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/09 20:01:06 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

long	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (!str[i])
		(write(2, "Error\n", 6), exit(1));
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		(write(2, "Error\n", 6), exit(1));
	return (r * s);
}

int	is_not_sort(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*find_max(t_stack *a)
{
	t_stack	*biggest;
	t_stack	*current;

	biggest = a;
	current = a -> next;
	while (current)
	{
		if (biggest->value < current->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		retate_n (a, 'a');
	else if ((*a)->next == biggest)
		rev_rotate_n (a, 'a');
	if ((*a)->value > (*a)->next->value)
		swap_n(a, 'a');
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
