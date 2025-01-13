/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:55:59 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 19:15:02 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*target;
	int				push_cost;
	bool			cheapest;
	bool			median;
	int				value;
	int				index;
}	t_stack;

int		lst_size(t_stack *node);
void	swap_n(t_stack **n, char stack);
void	swap_s(t_stack **a, t_stack **b);
void	push_n(t_stack **n1, t_stack **n2, char stack);
void	retate_n(t_stack **n, char stack);
void	retate_s(t_stack **a, t_stack **b);
void	rev_rotate_n(t_stack **n, char stack);
void	rev_rotate_s(t_stack **a, t_stack **b);
char	**ft_split(char *s, char c);
long	ft_atoi(char *str);
void	free_stack(t_stack **stack);
int		is_not_sort(t_stack *stack);
void	sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
t_stack	*find_max(t_stack *a);
void	position(t_stack *n);
void	decliration_to_b(t_stack *a, t_stack *b);
void	push_to_a(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char *s, int start, int len);
void	cleanup(char **ptr);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);
void	read_argv(t_stack **a, t_stack **b);
void	free_error(t_stack **a);

#endif