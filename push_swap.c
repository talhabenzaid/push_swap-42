/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:45 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/09 19:57:34 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*temp;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = (int)n;
	node->cheapest = 0;
	if (*a == NULL)
		*a = node;
	else
	{
		temp = *a;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}

void	free_error(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	(write(2, "ERROR\n", 6), exit(1));
}

int	duplicate(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	check_fill_a(t_stack **a, char **argv)
{
	long	n;
	int		i;
	char	**str;
	int		j;

	i = 1;
	while (argv[i])
	{
		str = ft_split (argv[i], ' ');
		if (!str)
			free_error(a);
		j = 0;
		while (str[j])
		{
			n = ft_atoi(str[j]);
			if (duplicate(*a, (int)n) || n > INT_MAX || n < INT_MIN)
				free_error(a);
			(free(str[j]), fill_a(a, (int)n));
			j++;
		}
		if (j == 0)
			(write(2, "Error\n", 6), exit(1));
		free (str);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
		(write (2, "Error\n", 6), exit (1));
	check_fill_a(&a, argv);
	if (is_not_sort (a))
	{
		if (lst_size (a) == 2)
			swap_n(&a, 'a');
		else if (lst_size (a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	free_stack (&a);
}
