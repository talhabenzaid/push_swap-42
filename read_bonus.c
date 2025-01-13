/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:06:00 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/09 23:13:24 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_operation(char *operation, t_stack **a, t_stack **b)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap_n(a, ' ');
	else if (ft_strcmp(operation, "sb") == 0)
		swap_n(b, ' ');
	else if (ft_strcmp(operation, "ss") == 0)
		swap_s(a, b);
	else if (ft_strcmp(operation, "pa") == 0)
		push_n(b, a, ' ');
	else if (ft_strcmp(operation, "pb") == 0)
		push_n(a, b, ' ');
	else if (ft_strcmp(operation, "ra") == 0)
		retate_n(a, ' ');
	else if (ft_strcmp(operation, "rb") == 0)
		retate_n(b, ' ');
	else if (ft_strcmp(operation, "rr") == 0)
		retate_s(a, b);
	else if (ft_strcmp(operation, "rra") == 0)
		rev_rotate_n(a, ' ');
	else if (ft_strcmp(operation, "rrb") == 0)
		rev_rotate_n(b, ' ');
	else if (ft_strcmp(operation, "rrr") == 0)
		rev_rotate_s(a, b);
	else
		(write(2, "Error\n", 6), exit(1));
}

void	do_operation(char **operation, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (operation[i])
	{
		handle_operation(operation[i], a, b);
		i++;
	}
}

void	free_split_operation(char **split_operation)
{
	int	i;

	i = 0;
	while (split_operation[i])
	{
		free(split_operation[i]);
		i++;
	}
	free(split_operation);
}

void	read_argv(t_stack **a, t_stack **b)
{
	char	*next;
	char	*operation;
	char	*tmp;
	char	**split_operation;

	operation = ft_strdup("");
	if (!operation)
		return (free_error(a));
	next = get_next_line(0);
	while (next)
	{
		tmp = operation;
		operation = ft_strjoin(operation, next);
		if (!operation)
			return (free(next), free(tmp), free_error(a));
		(free(tmp), free(next));
		next = get_next_line(0);
	}
	free(next);
	split_operation = ft_split(operation, '\n');
	if (!split_operation)
		(free(operation), free_error(a));
	do_operation(split_operation, a, b);
	free_split_operation(split_operation);
	free(operation);
}
